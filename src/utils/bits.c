#include "utils/bits.h"

unsigned long long int test_bit(unsigned long long int x, size_t n)
{
	return (x >> n) & 1ULL;
}

unsigned long long int set_bit(unsigned long long int x, size_t n)
{
	return x | (1ULL << n);
}

unsigned long long int reset_bit(unsigned long long int x, size_t n)
{
	return x & ~(1UL << n);
}

unsigned long long int toggle_bit(unsigned long long int x, size_t n)
{
	return x ^ (1ULL << n);
}

unsigned long long int change_bit(unsigned long long int x, size_t n, unsigned int s)
{
	return (x & ~(1ULL << n)) | ((unsigned long long int)!!s << n);
}