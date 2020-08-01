#include "arch/x86_64/interrupts/isr.h"
#include "arch/x86_64/interrupts/idt.h"
#include "libk/libk.h"

void isr_load()
{
    idt_set_gate(0,  (uint64_t)isr0);
    idt_set_gate(1,  (uint64_t)isr1);
    idt_set_gate(2,  (uint64_t)isr2);
    idt_set_gate(3,  (uint64_t)isr3);
    idt_set_gate(4,  (uint64_t)isr4);
    idt_set_gate(5,  (uint64_t)isr5);
    idt_set_gate(6,  (uint64_t)isr6);
    idt_set_gate(7,  (uint64_t)isr7);
    idt_set_gate(8,  (uint64_t)isr8);
    idt_set_gate(9,  (uint64_t)isr9);
    idt_set_gate(10, (uint64_t)isr10);
    idt_set_gate(11, (uint64_t)isr11);
    idt_set_gate(12, (uint64_t)isr12);
    idt_set_gate(13, (uint64_t)isr13);
    idt_set_gate(14, (uint64_t)isr14);
    idt_set_gate(15, (uint64_t)isr15);
    idt_set_gate(16, (uint64_t)isr16);
    idt_set_gate(17, (uint64_t)isr17);
    idt_set_gate(18, (uint64_t)isr18);
    idt_set_gate(19, (uint64_t)isr19);
    idt_set_gate(20, (uint64_t)isr20);
    idt_set_gate(21, (uint64_t)isr21);
    idt_set_gate(22, (uint64_t)isr22);
    idt_set_gate(23, (uint64_t)isr23);
    idt_set_gate(24, (uint64_t)isr24);
    idt_set_gate(25, (uint64_t)isr25);
    idt_set_gate(26, (uint64_t)isr26);
    idt_set_gate(27, (uint64_t)isr27);
    idt_set_gate(28, (uint64_t)isr28);
    idt_set_gate(29, (uint64_t)isr29);
    idt_set_gate(30, (uint64_t)isr30);
    idt_set_gate(31, (uint64_t)isr31);
    idt_load();
}

char* exception_messages[] = 
{
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",    
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",    
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",    
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handle(uint64_t code)
{
   kprintf("%s\n", exception_messages[code]);
}
