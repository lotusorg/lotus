#ifndef __STDLIB_H__
#define __STDLIB_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void* memcpy(void* dest, const void* src, size_t count);

#ifdef __cplusplus
}
#endif

#endif /* __STDLIB_H__ */