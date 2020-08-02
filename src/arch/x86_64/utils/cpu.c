#include "arch/x86_64/utils/cpu.h"

void outb(uint16_t port, uint8_t val)
{
    asm volatile(
        "movw %[port], %%dx \n"
        "movb %[val], %%al \n"
        "outb %%al, %%dx \n"
        :  /* output */ 
        : [port] "r" (port), [val] "r" (val) /* input */
        : "al", "dx" /* clobbers */
    );
}

void outw(uint16_t port, uint16_t val)
{
    asm volatile(
        "movw %[port], %%dx \n"
        "movw %[val], %%ax \n"
        "outw %%ax, %%dx \n"
        :  /* output */ 
        : [port] "r" (port), [val] "r" (val) /* input */
        : "ax", "dx" /* clobbers */
    );
}

void outl(uint16_t port, uint32_t val)
{
    asm volatile(
        "movw %[port], %%dx \n"
        "movl %[val], %%eax \n"
        "outl %%eax, %%dx \n"
        :  /* output */ 
        : [port] "r" (port), [val] "r" (val) /* input */
        : "eax", "dx" /* clobbers */
    );
}

uint8_t inb(uint16_t port)
{
    uint8_t ret;

    asm volatile(
        "movw %[port], %%dx \n"
        "inb %%dx, %%al \n"
        "movb %%al, %[ret] \n"
        : [ret] "=r" (ret) /* output */ 
        : [port] "r" (port) /* input */
        : "al", "dx" /* clobbers */
    );

    return ret;
}

uint16_t inw(uint16_t port)
{
    uint16_t ret;

    asm volatile(
        "movw %[port], %%dx \n"
        "inw %%dx, %%ax \n"
        "movw %%ax, %[ret] \n"
        : [ret] "=r" (ret) /* output */ 
        : [port] "r" (port) /* input */
        : "ax", "dx" /* clobbers */
    );

    return ret;
}

uint32_t inl(uint16_t port)
{
    uint32_t ret;

    asm volatile(
        "movw %[port], %%dx \n"
        "inl %%dx, %%eax \n"
        "movl %%eax, %[ret] \n"
        : [ret] "=r" (ret) /* output */ 
        : [port] "r" (port) /* input */
        : "eax", "dx" /* clobbers */
    );

    return ret;
}