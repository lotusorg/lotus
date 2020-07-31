#include "isr.h"
#include "idt.h"
#include "libk/screen.h"
#include "libk/libk.h"

void
isr_load()
{

        idt_set_gate(0,  (u64)isr0);
        idt_set_gate(1,  (u64)isr1);
        idt_set_gate(2,  (u64)isr2);
        idt_set_gate(3,  (u64)isr3);
        idt_set_gate(4,  (u64)isr4);
        idt_set_gate(5,  (u64)isr5);
        idt_set_gate(6,  (u64)isr6);
        idt_set_gate(7,  (u64)isr7);
        idt_set_gate(8,  (u64)isr8);
        idt_set_gate(9,  (u64)isr9);
        idt_set_gate(10, (u64)isr10);
        idt_set_gate(11, (u64)isr11);
        idt_set_gate(12, (u64)isr12);
        idt_set_gate(13, (u64)isr13);
        idt_set_gate(14, (u64)isr14);
        idt_set_gate(15, (u64)isr15);
        idt_set_gate(16, (u64)isr16);
        idt_set_gate(17, (u64)isr17);
        idt_set_gate(18, (u64)isr18);
        idt_set_gate(19, (u64)isr19);
        idt_set_gate(20, (u64)isr20);
        idt_set_gate(21, (u64)isr21);
        idt_set_gate(22, (u64)isr22);
        idt_set_gate(23, (u64)isr23);
        idt_set_gate(24, (u64)isr24);
        idt_set_gate(25, (u64)isr25);
        idt_set_gate(26, (u64)isr26);
        idt_set_gate(27, (u64)isr27);
        idt_set_gate(28, (u64)isr28);
        idt_set_gate(29, (u64)isr29);
        idt_set_gate(30, (u64)isr30);
        idt_set_gate(31, (u64)isr31);
        idt_load();
}

char *exception_messages[] = {
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

void
isr_handle(u64 code)
{
        kprintf(exception_messages[code]);
        kprintf("\n");
}
