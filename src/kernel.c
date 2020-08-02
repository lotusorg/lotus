#include "boot/stivale/stivale.h"
#include "libk/screen.h"
#include "libk/libk.h"
#include "mm/mm.h"
#include "arch/arch.h"

char stack[65536] __attribute__((section (".kernel_stack"))) = {0};

__attribute__((section(".stivalehdr"), used))
struct stivale_header header = {
    .stack = (uintptr_t)stack + sizeof(stack),
    .framebuffer_bpp = 0,
    .framebuffer_width = 0,
    .framebuffer_height = 0,
    .flags = 0,
    .entry_point = 0
};

void kmain(struct stivale_struct* stivale_struct)
{
    screen_init();

    kprintf("hello kernel world!\n");

    pmm_init(stivale_struct);

    init_arch();

    while(1);
}