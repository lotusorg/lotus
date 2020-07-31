#ifndef __IDT_H_
#define __IDT_H_

#include "type.h"

#define KERNEL_CS 0x08

/*
 * Define the idt data structure as described here:
 * https://wiki.osdev.org/Interrupt_Descriptor_Table.
 */
typedef struct {
        u16 addr_1;    /* offset bits 0..15 */
        u16 ksel;      /* a code segment selector in GDT or LDT */
        u8  ist;       /* bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.*/
        u8  type_attr; /* type and attributes */
        u16 addr_2;    /* address bits 16..31 */
        u32 addr_3;    /* address bits 32..63 */
        u32 zero;      /* always 0 */
} __attribute__((packed)) idt_entry_t;

/*
 * Structure used by lidt to load the IDT.
 */
typedef struct {
        u16 limit;   /* Size of the table. */
        u64 address; /* Address of the base of the IDT. */
} __attribute__((packed)) idt_info_t;

/* The IDT consists of 256 entries even though some of them are NULL. */
idt_entry_t idt[256];
idt_info_t  idt_info;

void idt_set_gate(int, u64);
void idt_load();

#endif // __IDT_H_
