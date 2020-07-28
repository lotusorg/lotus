#include "arch/x86_64/drivers/vga/vga.h"

#include <stddef.h>

#define vga_default_color (VGA_COLOR_LIGHT_GREY | (VGA_COLOR_BLACK << 4))


static uint16_t* vga_buffer = (void*)0xb8000;
static unsigned int max_height = 25;
static unsigned int max_width = 80;

static uint8_t console_color = vga_default_color;

static unsigned int height = 0;
static unsigned int width = 0;

uint16_t vga_merge_char_color(unsigned char uc, uint8_t color)
{
	return (uint16_t)uc | (uint16_t)color << 8;
}

void vga_init() 
{ 

}

void vga_disable()
{
    console_color = vga_merge_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    height = 0;
    width = 0;

    for (size_t i = 0; i < max_height * max_width; i++)
    {
        vga_putchar(' ');
    }
}

void vga_putchar(char c)
{
    if (c == '\n')
    {
        width = 0;
        height++;
    }
    else
    {
        uint16_t vga_entry = vga_merge_char_color(c, console_color);
        vga_buffer[height * max_width + width] = vga_entry;
        width++;
    } 
    
    if (max_width < width)
    {
        width = 0;
        height++;     
    }
    if (max_height < height)
    {
        height = 0;
    }
}

void vga_set_color(uint8_t color)
{
    console_color = color;
}

uint8_t vga_merge_color(enum vga_color foreground_color, enum vga_color background_color)
{
    return foreground_color | (background_color << 4);
}

void vga_set_cursor_pos(unsigned int x, unsigned int y)
{
    width = x % (max_width + 1);
    height = y % (max_height + 1);
}

void vga_get_cursor_pos(unsigned int* x, unsigned int* y)
{
    *x = width;
    *y = height;
}
