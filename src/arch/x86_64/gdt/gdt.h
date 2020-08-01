#ifndef __GDT_H__
#define __GDT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct gdt_info
{
    uint16_t length;
    uint64_t gdt_ptr;
};

struct gdt_struct
{
    uint64_t zero;
    uint64_t code;
    uint64_t data;
} __attribute__((packed));

/* credit for https://wiki.osdev.org/Global_Descriptor_Table */
struct gdt_entry
{
    uint16_t limit_low;  /* low 16 bits of limit */
    uint16_t base_low;   /* low 16 bits of base */
    uint8_t base_mid;   /* middle 8 bits of base */
    union
    {
        struct
        {
            unsigned int accessed_bit : 1;
            unsigned int read_write_bit : 1;
            unsigned int direction_conforming_bit : 1;
            unsigned int executable_bit : 1; /* If 1 code in this segment can be executed, ie. a code selector. If 0 it is a data selector. */
            unsigned int descriptor_type_bit : 1; /* his bit should be set for code or data segments and should be cleared for system segments */
            unsigned int privilege : 2; /* 0 = highest (kernel), 3 = lowest (user applications) */
            unsigned int present_bit : 1; /* This must be 1 for all valid selectors */
        } __attribute__((packed));
        
        uint8_t access_byte;
    } __attribute__((packed));
    uint8_t limit_high : 4; /* highest 4 bits of limits */
    union 
    {
        struct
        {
            unsigned int : 1;
            unsigned int l_bit : 1; /* is used to indicate x86-64 code descriptor */
            unsigned int size_bit : 1; /* has to be 0 when the L bit is set, as the combination Sz = 1, L = 1 is reserved for future use (and will throw an exception if you try to use it) */
            unsigned int granularity_bit : 1; /* If 0 the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KiB blocks (page granularity) */
        } __attribute__((packed));
        uint8_t flags : 4;
    } __attribute__((packed));
    uint8_t base_high; /* highest 8 bits of base */
} __attribute__((packed));

_Static_assert (sizeof(struct gdt_entry) != sizeof(uint64_t), "gdt entry should have the same size of uint64_t");

void load_gdt();

#ifdef __cplusplus
}
#endif

#endif /* __GDT_H__ */