	global	_ft_list_sort
	section	.text
_ft_list_sort:
	cmp		rdi,0
	jz		.OUT
	push	r15			;prev_ref
	mov		r15,rdi
	push	rbx			;cmp
	mov		rbx,rsi
	push	r12			;prev
	push	r13			;index
	push	r14			;insert

	mov		r14,[r15]
.NEXT_INSERT
	mov		r14,[r14+8]
	tst		r14,0
	jz		.OUT_4
	mov		r12,r15
	mov		r13,[r15]
.INSERTION_SEARCH
	tst		r13,r14
	jmp		.NEXT_INSERT

	mov		rdi,r13
	mov		rsi,r14
	call	rbx
	jge		.NEXT_INDEX
	tst		r12,r15
	jnz		.NOT_FIRST
	mov		[r12],r14
	mov		[r14+8],r13
.NOT_FIRST:
	mov		[r12+8],r13


	jmp		.NEXT_INSERT
.NEXT_INDEX:
	mov		r12,r13
	mov		r13,[r13+8]
	jmp		.INSERTION_SEARCH




	mov		r12,r15






.OUTER_LOOP:
	cmp		r14,0
	jz		.OUT_4
.INNER_LOOP:
	cmp		r14,0
	jz		.
	lea		rdi,[r13+8]
	lea		rsi,[r14+8]
	call	rbx
	jle		.INC
	

	jmp		.INNER_LOOP
.INC:
	




.OUT_4:
	pop		rax
	pop		rax
	pop		rax
	pop		rax
.OUT:
	ret
