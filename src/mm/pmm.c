#include "mm/mm.h"
#include "limits.h"
#include "utils/bits.h"
#include "utils/spinlock.h"
#include "libk/libk.h"

spinlock_t pmm_lock = new_spinlock;

/* 
    every bit in the bitset represent a page (ptr = bit_set_index * PAGE_SIZE)
    if a bit in the bitset is 0, its means the page is available
    if a bit in the bitset is 1, its means the page is not available
*/
static unsigned char* bitsetptr;
static size_t bitset_size; /* in unsigned char */
static size_t bitset_len; /* in bits */

/* set all the bits in the range <bitset_index> - <bitset_index + length> to 1 */
static void set_bitset_bits(size_t bitset_index, size_t length)
{
    for (size_t i = bitset_index; i < bitset_index + length; i++)
    {
        size_t uc_index = i / CHAR_BIT;
        size_t bit_index = i % CHAR_BIT;

       bitsetptr[uc_index]  = set_bit(bitsetptr[uc_index], bit_index);
    }
}

/* set all the bits in the range <bitset_index> - <bitset_index + length> to 0 */
static void reset_bitset_bits(size_t bitset_index, size_t length)
{
    for (size_t i = bitset_index; i < bitset_index + length; i++)
    {
        size_t uc_index = i / CHAR_BIT;
        size_t bit_index = i % CHAR_BIT;

        bitsetptr[uc_index] = reset_bit(bitsetptr[uc_index], bit_index);
    }
}

/*  get the <bitset_index> bit in the biteset */
static int get_bitset_bit(size_t bitset_index)
{
    size_t uc_index = bitset_index / CHAR_BIT;
    size_t bit_index = bitset_index % CHAR_BIT;

    return test_bit(bitsetptr[uc_index], bit_index);
}

void pmm_init(struct stivale_struct* stivale_struct)
{
    struct mmap_entry* mmapptr = (struct mmap_entry*) stivale_struct->memory_map_addr;
    size_t mmaplen = stivale_struct->memory_map_entries;

    #ifdef DEBUG

    kprintf("stivale memory map:\n");

    for (size_t i = 0; i < mmaplen; i++)
    {
        kprintf("base: %p, length: %lli, type: %i\n", mmapptr[i].base, mmapptr[i].length, mmapptr[i].type);
    }
    
    kprintf("\n");

    #endif

    /* find the largest memory address */
    uintptr_t max_ptr = 0;
    for (size_t i = 0; i < mmaplen; i++)
    {
        uintptr_t current_ptr = mmapptr[i].base + mmapptr[i].length;
        if (max_ptr < current_ptr)
        {
            max_ptr = current_ptr;
        }
    }
    
    bitset_len = max_ptr / PAGE_SIZE;
    bitset_size =  bitset_len / CHAR_BIT;

    /* search for a memory place with enough place for the bitset*/
    for (size_t i = 0; i < mmaplen; i++)
    {
        if ((mmapptr[i].type == STIVALE_MMAP_ENTRY_USABLE) && (bitset_size <= mmapptr[i].length))
        {
            bitsetptr = (void*) mmapptr[i].base;
            break;
        }
    }

    /* set all bits in the bitset to 1 */
    for (size_t i = 0; i < bitset_size; i++)
    {
        bitsetptr[i] = -1;
    }
    
    /* mark all usable pages */
    for (size_t i = 0; i < mmaplen; i++)
    {
        if (mmapptr[i].type == STIVALE_MMAP_ENTRY_USABLE)
        {
            reset_bitset_bits(mmapptr[i].base / PAGE_SIZE, mmapptr[i].length / PAGE_SIZE);
        }
    }

    /* the expression in the second parameter is how many pages needed for the bitset */
    set_bitset_bits((uintptr_t)bitsetptr / PAGE_SIZE, bitset_size / PAGE_SIZE + (bitset_size % PAGE_SIZE != 0));
}

void* pmm_alloc(size_t page_count)
{   
    if (page_count == 0 || page_count >= bitset_len)
	{
		return NULL;
	}

    acquire_spinlock(&pmm_lock);

    size_t i = 0;
	size_t available = 0;

	for (; (i < bitset_len) && (available < page_count); i++)
	{   
		if(get_bitset_bit(i) != 0) // if page is unavailable
		{
			available = 0;
			continue;
		}
		
		available++;
	}
	
	if (available != page_count)
	{
        panic("MM: requested %i pages, pmm can only supply %i pages", page_count, available);
        release_spinlock(&pmm_lock);
		return NULL;
	}
    
    set_bitset_bits(i - page_count, page_count);

    release_spinlock(&pmm_lock);

    return (void*) ((i - page_count) * PAGE_SIZE);
}

void pmm_free(void* ptr, size_t page_count)
{
    acquire_spinlock(&pmm_lock);

    reset_bitset_bits((uintptr_t)ptr / PAGE_SIZE, page_count);

    release_spinlock(&pmm_lock);
}
