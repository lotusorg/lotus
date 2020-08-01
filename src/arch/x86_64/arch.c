#include "arch/arch.h"
#include "arch/x86_64/gdt/gdt.h"
#include "arch/x86_64/interrupts/isr.h"

void init_arch(void)
{
    load_gdt();
    isr_load();
}