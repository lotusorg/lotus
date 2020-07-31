#include "libk/libk.h"
#include <stdint.h>
#include <stdlib.h>
#include "mm/mm.h"

static uint64_t kmalloc_info_magic_number = 0xDEADBEEFCAFEBABE;

uint64_t calculate_kmalloc_info_checksum(void* ptr)
{
	return ((uint64_t)ptr ^ kmalloc_info_magic_number);
}

struct kmalloc_info
{
	size_t allocated_pages;
	size_t allocated_memory_size;
	size_t requested_memory_size;
	uint64_t checksum;
};

void* kmalloc(size_t size)
{
	size_t block_size = size + sizeof(struct kmalloc_info);
	size_t requsted_page_frames = (block_size / PAGE_SIZE) + ((block_size % PAGE_SIZE) != 0);
	
	void* blockptr = pmm_alloc(requsted_page_frames);
	
	struct kmalloc_info* infoptr = blockptr;
	infoptr->allocated_pages = requsted_page_frames;
	infoptr->allocated_memory_size = requsted_page_frames * PAGE_SIZE - sizeof(struct kmalloc_info);
	infoptr->requested_memory_size = size;
	infoptr->checksum = calculate_kmalloc_info_checksum((void*)((uintptr_t)blockptr + sizeof(struct kmalloc_info)));
	
	return (void*)((uintptr_t)blockptr + sizeof(struct kmalloc_info));
}

void kfree(void* ptr)
{
	struct kmalloc_info* infoptr = (void*)((uintptr_t)ptr - sizeof(struct kmalloc_info));
	
	if(infoptr->checksum != calculate_kmalloc_info_checksum(ptr))
	{
		panic("LIBK: kfree() cant free pointer %p, bad checksum");
		return;
	}
	
    infoptr->checksum = infoptr->checksum + 1; /* invalidate the checksum */
	pmm_free((void*)infoptr, infoptr->allocated_pages);
}

void* krealloc(void* ptr, size_t size)
{
	if(ptr == NULL)
	{
		return kmalloc(size);
	}

	struct kmalloc_info* infoptr = (void*)((uintptr_t)ptr - sizeof(struct kmalloc_info));	
	
	if(infoptr->checksum != calculate_kmalloc_info_checksum(ptr))
	{
		panic("LIBK: krealloc() failed. ptr=%p, size=%lli, bad checksum", ptr, size);
		return NULL;
	}
	
	if(size <= infoptr->allocated_memory_size)
	{
		infoptr->requested_memory_size = size;
		return ptr;
	}

	void* new_ptr = kmalloc(size);

	memcpy(new_ptr, ptr, size);

	kfree(ptr);

	return new_ptr;
}