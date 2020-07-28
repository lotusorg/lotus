#include "libk/libk.h"
#include "printf.h"
#include <stdint.h>
#include "libk/screen.h"

// FULL CREDIT TO https://github.com/mpaland/printf/
typedef void (*out_fct_type)(char character, void* buffer, size_t idx, size_t maxlen);

// FULL CREDIT TO https://github.com/mpaland/printf/
typedef struct {
  void  (*fct)(char character, void* arg);
  void* arg;
} out_fct_wrap_type;

// FULL CREDIT TO https://github.com/mpaland/printf/
static inline void _out_fct(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)idx; (void)maxlen;
  if (character) {
    // buffer is the output fct pointer
    ((out_fct_wrap_type*)buffer)->fct(character, ((out_fct_wrap_type*)buffer)->arg);
  }
}

// from https://github.com/mpaland/printf/
extern int _vsnprintf(out_fct_type out, char* buffer, const size_t maxlen, const char* format, va_list va);

void _putchar(char character)
{
  (void)character;
}

static void kputchar(char c, void* arg)
{
  (void)arg;
  screen_putchar(c);
}

// FULL CREDIT TO https://github.com/mpaland/printf/
int vkprintf(const char* format, va_list va)
{
    const out_fct_wrap_type out_fct_wrap = { kputchar, NULL };
    return _vsnprintf(_out_fct, (char*)(uintptr_t)&out_fct_wrap, (size_t)-1, format, va);
}

int kprintf(const char* format, ...)
{
    va_list args;

    va_start(args, format);

    int ret = vkprintf(format, args);

    va_end(args);

    return ret;
}