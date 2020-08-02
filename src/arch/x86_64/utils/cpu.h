#ifndef __X86_64_CPU_H__
#define __X86_64_CPU_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
    write <val> into <port> port in the cpu
    b suffix stands for uint8_t, w suffix stands for uint16_t, l suffix stands for uint32_t (its the size of the written value)
*/
void outb(uint16_t port, uint8_t val);
void outw(uint16_t port, uint16_t val);
void outl(uint16_t port, uint32_t val);


/*
    read from <port> port in the cpu
    b suffix stands for uint8_t, w suffix stands for uint16_t, l suffix stands for uint32_t (its the size of the readed value)
*/
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);
uint32_t inl(uint16_t port);

#ifdef __cplusplus
}
#endif

#endif /* __X86_64_CPU_H__ */