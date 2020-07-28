#ifndef __MM_H__
#define __MM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define PAGE_SIZE ((size_t)4096)

void pmm_init(struct stivale_struct stivale_struct);
void* pmm_alloc(size_t page_count);
void pmm_free(void* ptr, size_t page_count);

#ifdef __cplusplus
}
#endif

#endif /* __MM_H__ */
