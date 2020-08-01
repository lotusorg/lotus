#ifndef __IDT_H__
#define __IDT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define KERNEL_CS 0x08

/*
 * Define the idt data structure as described here:
 * https://wiki.osdev.org/Interrupt_Descriptor_Table.
 */
typedef struct {
        uint16_t addr_1;    /* offset bits 0..15 */
        uint16_t ksel;      /* a code segment selector in GDT or LDT */
        uint8_t  ist;       /* bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.*/
        uint8_t  type_attr; /* type and attributes */
        uint16_t addr_2;    /* address bits 16..31 */
        uint32_t addr_3;    /* address bits 32..63 */
        uint32_t zero;      /* always 0 */
} __attribute__((packed)) idt_entry_t;

/*
 * Structure used by lidt to load the IDT.
 */
typedef struct {
        uint16_t limit;   /* Size of the table. */
        uint64_t address; /* Address of the base of the IDT. */
} __attribute__((packed)) idt_info_t;

/* The IDT consists of 256 entries even though some of them are NULL. */
idt_entry_t idt[256];
idt_info_t  idt_info;

void idt_set_gate(int gate_number, uint64_t handler);
void idt_load();

#ifdef __cplusplus
}
#endif

#endif // __IDT_H__
