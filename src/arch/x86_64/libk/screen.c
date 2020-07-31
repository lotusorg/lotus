#include "libk/screen.h"
#include "arch/x86_64/devices/vga/vga.h"

void screen_init()
{
    vga_init();
}

int screen_putchar(int c)
{
    vga_putchar(c);
    return c;
}