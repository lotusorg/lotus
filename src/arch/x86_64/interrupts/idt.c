#include "arch/x86_64/interrupts/idt.h"

void idt_set_gate(int n, uint64_t handler)
{
    idt[n].addr_1    = handler & 0xFFFF;
    idt[n].ksel      = KERNEL_CS;
    idt[n].ist       = 0;
    idt[n].addr_2    = (handler >> 16) & 0xFFFF;
    idt[n].addr_1    =  handler >> 32;
    idt[n].zero      = 0;
    idt[n].type_attr = 0x8E;
}

void idt_load()
{
    idt_info.address = (uint64_t) &idt;
    idt_info.limit   = 256 * sizeof(idt_entry_t) - 1;
    asm volatile("lidt (%0)" 
                    :
                    : "r" (&idt_info));
}
