#include "arch/x86_64/gdt/gdt.h"
#include <stdint.h>

static struct gdt_struct gdt_struct;

static struct gdt_info gdt_info =
{
    .length = sizeof(struct gdt_struct),
    .gdt_ptr = (uint64_t) &gdt_struct
};

void load_gdt()
{   
    struct gdt_entry code = (struct gdt_entry) {
        .accessed_bit = 0,
        .read_write_bit = 1,
        .executable_bit = 1,
        .descriptor_type_bit = 1,
        .privilege = 0,
        .present_bit = 1,
        .l_bit = 1
    };

    struct gdt_entry data = (struct gdt_entry) {
        .accessed_bit = 0,
        .read_write_bit = 1,
        .descriptor_type_bit = 1,
        .privilege = 0,
        .present_bit = 1
    };

    gdt_struct = (struct gdt_struct) {
        .zero = 0ULL,
        .code = *(uint64_t*)&code,
        .data = *(uint64_t*)&data
    };  

    asm volatile("lgdt (gdt_info)"
                :
                : [ gdt_info ] "m" (gdt_info));
}