#ifndef __LIBK_H__
#define __LIBK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdarg.h>

void* kmalloc(size_t size);
void* kfree(void* ptr);

int kprintf(const char* fmt, ...);
int vkprintf(const char* fmt, va_list va);

__attribute__((noreturn)) void panic(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif