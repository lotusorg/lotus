[extern isr_handle]

; 0: Divide By Zero Exception
isr0:
	cli
	push QWORD 0
	push QWORD 0
	jmp isr_common_stub

; 1: Debug Exception
isr1:
	cli
	push QWORD 0
	push QWORD 1
	jmp isr_common_stub

; 2: Non Maskable Interrupt Exception
isr2:
	cli
	push QWORD 0
	push QWORD 2
	jmp isr_common_stub

; 3: Int 3 Exception
isr3:
	cli
	push QWORD 0
	push QWORD 3
	jmp isr_common_stub

; 4: INTO Exception
isr4:
	cli
	push QWORD 0
	push QWORD 4
	jmp isr_common_stub

; 5: Out of Bounds Exception
isr5:
	cli
	push QWORD 0
	push QWORD 5
	jmp isr_common_stub

; 6: Invalid Opcode Exception
isr6:
	cli
	push QWORD 0
	push QWORD 6
	jmp isr_common_stub

; 7: Coprocessor Not Available Exception
isr7:
	cli
	push QWORD 0
	push QWORD 7
	jmp isr_common_stub

; 8: Double Fault Exception (With Error Code!)
isr8:
	cli
	push QWORD 8
	jmp isr_common_stub

; 9: Coprocessor Segment Overrun Exception
isr9:
	cli
	push QWORD 0
	push QWORD 9
	jmp isr_common_stub

; 10: Bad TSS Exception (With Error Code!)
isr10:
	cli
	push QWORD 10
	jmp isr_common_stub

; 11: Segment Not Present Exception (With Error Code!)
isr11:
	cli
	push QWORD 11
	jmp isr_common_stub

; 12: Stack Fault Exception (With Error Code!)
isr12:
	cli
	push QWORD 12
	jmp isr_common_stub

; 13: General Protection Fault Exception (With Error Code!)
isr13:
	cli
	push QWORD 13
	jmp isr_common_stub

; 14: Page Fault Exception (With Error Code!)
isr14:
	cli
	push QWORD 14
	jmp isr_common_stub

; 15: Reserved Exception
isr15:
	cli
	push QWORD 0
	push QWORD 15
	jmp isr_common_stub

; 16: Floating Point Exception
isr16:
	cli
	push QWORD 0
	push QWORD 16
	jmp isr_common_stub

; 17: Alignment Check Exception
isr17:
	cli
	push QWORD 0
	push QWORD 17
	jmp isr_common_stub

; 18: Machine Check Exception
isr18:
	cli
	push QWORD 0
	push QWORD 18
	jmp isr_common_stub

; 19: Reserved
isr19:
	cli
	push QWORD 0
	push QWORD 19
	jmp isr_common_stub

; 20: Reserved
isr20:
	cli
	push QWORD 0
	push QWORD 20
	jmp isr_common_stub

; 21: Reserved
isr21:
	cli
	push QWORD 0
	push QWORD 21
	jmp isr_common_stub

; 22: Reserved
isr22:
	cli
	push QWORD 0
	push QWORD 22
	jmp isr_common_stub

; 23: Reserved
isr23:
	cli
	push QWORD 0
	push QWORD 23
	jmp isr_common_stub

; 24: Reserved
isr24:
	cli
	push QWORD 0
	push QWORD 24
	jmp isr_common_stub

; 25: Reserved
isr25:
	cli
	push QWORD 0
	push QWORD 25
	jmp isr_common_stub

; 26: Reserved
isr26:
	cli
	push QWORD 0
	push QWORD 26
	jmp isr_common_stub

; 27: Reserved
isr27:
	cli
	push QWORD 0
	push QWORD 27
	jmp isr_common_stub

; 28: Reserved
isr28:
	cli
	push QWORD 0
	push QWORD 28
	jmp isr_common_stub

; 29: Reserved
isr29:
	cli
	push QWORD 0
	push QWORD 29
	jmp isr_common_stub

; 30: Reserved
isr30:
	cli
	push QWORD 0
	push QWORD 30
	jmp isr_common_stub

; 31: Reserved
isr31:
	cli
	push QWORD 0
	push QWORD 31
	jmp isr_common_stub

isr_common_stub:
	mov rdi, [rsp]
	call isr_handle
	add rsp, 16 ; Cleans up the pushed error code and pushed ISR number.
	sti
	iretq
