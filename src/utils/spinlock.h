#ifndef __SPINLOCK_H__
#define __SPINLOCK_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef int spinlock_t;

#define new_spinlock 0
#define acquired_spinlock 1

__attribute__((always_inline)) static inline void acquire_spinlock(spinlock_t* lock)
{
    while(!__sync_bool_compare_and_swap((int*)lock, 0, 1)) while(lock) __builtin_ia32_pause();
} 

__attribute__((always_inline)) static inline void release_spinlock(spinlock_t* lock) 
{
    *lock = new_spinlock;
}

#ifdef __cplusplus
}
#endif

#endif /* __SPINLOCK_H__ */