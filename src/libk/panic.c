#include "libk/libk.h"

__attribute__((noreturn)) void panic(const char *fmt, ...) {
    asm volatile ("cli");
    
    // TODO: draw the word panic in red
    
    kprintf("PANIC: ");

    va_list args;

    va_start(args, fmt);

    vkprintf(fmt, args);

    va_end(args);

    for (;;) {
        asm volatile ("hlt");
    }
}
