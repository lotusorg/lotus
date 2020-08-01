/* 0: Divide By Zero Exception */
isr0:
	cli
	pushq 0
	pushq 0
	jmp isr_common_stub

/* 1: Debug Exception */
isr1:
	cli
	pushq 0
	pushq 1
	jmp isr_common_stub

/* 2: Non Maskable Interrupt Exception */
isr2:
	cli
	pushq 0
	pushq 2
	jmp isr_common_stub

/* 3: Int 3 Exception */
isr3:
	cli
	pushq 0
	pushq 3
	jmp isr_common_stub

/* 4: INTO Exception */
isr4:
	cli
	pushq 0
	pushq 4
	jmp isr_common_stub

/* 5: Out of Bounds Exception */
isr5:
	cli
	pushq 0
	pushq 5
	jmp isr_common_stub

/* 6: Invalid Opcode Exception */
isr6:
	cli
	pushq 0
	pushq 6
	jmp isr_common_stub

/* 7: Coprocessor Not Available Exception */
isr7:
	cli
	pushq 0
	pushq 7
	jmp isr_common_stub

/* 8: Double Fault Exception (With Error Code!) */
isr8:
	cli
	pushq 8
	jmp isr_common_stub

/* 9: Coprocessor Segment Overrun Exception */
isr9:
	cli
	pushq 0
	pushq 9
	jmp isr_common_stub

/* 10: Bad TSS Exception (With Error Code!) */
isr10:
	cli
	pushq 10
	jmp isr_common_stub

/* 11: Segment Not Present Exception (With Error Code!) */
isr11:
	cli
	pushq 11
	jmp isr_common_stub

/* 12: Stack Fault Exception (With Error Code!) */
isr12:
	cli
	pushq 12
	jmp isr_common_stub

/* 13: General Protection Fault Exception (With Error Code!) */
isr13:
	cli
	pushq 13
	jmp isr_common_stub

/* 14: Page Fault Exception (With Error Code!) */
isr14:
	cli
	pushq 14
	jmp isr_common_stub

/* 15: Reserved Exception */
isr15:
	cli
	pushq 0
	pushq 15
	jmp isr_common_stub

/* 16: Floating Point Exception */
isr16:
	cli
	pushq 0
	pushq 16
	jmp isr_common_stub

/* 17: Alignment Check Exception */
isr17:
	cli
	pushq 0
	pushq 17
	jmp isr_common_stub

/* 18: Machine Check Exception */
isr18:
	cli
	pushq 0
	pushq 18
	jmp isr_common_stub

/* 19: Reserved */
isr19:
	cli
	pushq 0
	pushq 19
	jmp isr_common_stub

/* 20: Reserved */
isr20:
	cli
	pushq 0
	pushq 20
	jmp isr_common_stub

/* 21: Reserved */
isr21:
	cli
	pushq 0
	pushq 21
	jmp isr_common_stub

/* 22: Reserved */
isr22:
	cli
	pushq 0
	pushq 22
	jmp isr_common_stub

/* 23: Reserved */
isr23:
	cli
	pushq 0
	pushq 23
	jmp isr_common_stub

/* 24: Reserved */
isr24:
	cli
	pushq 0
	pushq 24
	jmp isr_common_stub

/* 25: Reserved */
isr25:
	cli
	pushq 0
	pushq 25
	jmp isr_common_stub

/* 26: Reserved */
isr26:
	cli
	pushq 0
	pushq 26
	jmp isr_common_stub

/* 27: Reserved */
isr27:
	cli
	pushq 0
	pushq 27
	jmp isr_common_stub

/* 28: Reserved */
isr28:
	cli
	pushq 0
	pushq 28
	jmp isr_common_stub

/* 29: Reserved */
isr29:
	cli
	pushq 0
	pushq 29
	jmp isr_common_stub

/* 30: Reserved */
isr30:
	cli
	pushq 0
	pushq 30
	jmp isr_common_stub

/* 31: Reserved */
isr31:
	cli
	pushq 0
	pushq 31
	jmp isr_common_stub

isr_common_stub:
	movq (rsp), %rdi
	call isr_handle
	addq 16, %rsp /* Cleans up the pushed error code and pushed ISR number. */
	sti
	iretq
