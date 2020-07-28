OUTPUT_FORMAT(elf64-x86-64)
ENTRY(kmain)

SECTIONS
{
	kernel_phys_offset = 0xffffffff80000000;
    . = kernel_phys_offset + 0x100000;

    .stivalehdr BLOCK(4K) : ALIGN(4K)
    {
        KEEP(*(.stivalehdr*))
    }

	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.text*)
	}
 
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata*)
	}
 
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data*)
	}

	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON*)
		*(.bss*)
	}

	.kernel_stack BLOCK(4K) : ALIGN(4K)
    {
       *(.kernel_stack*)
    }
}