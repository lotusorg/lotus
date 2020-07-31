#ifndef __BITS_H__
#define __BITS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/* return the bit n inside integer x */
unsigned long long int test_bit(unsigned long long int x, size_t n);

/* set the bit n inside integer x to 1 */
unsigned long long int set_bit(unsigned long long int x, size_t n);

/* set the bit n inside integer x to 0 */
unsigned long long int reset_bit(unsigned long long int x, size_t n);

/* toggle the bit n inside integer x */
unsigned long long int toggle_bit(unsigned long long int x, size_t n);

/* set the bit n inside integer x to state s
   s can only be 0 or 1 */
unsigned long long int change_bit(unsigned long long int x, size_t n, unsigned int s);

#ifdef __cplusplus
}
#endif

#endif /* __BITS_H__ */