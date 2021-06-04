	global	_ft_list_sort
	section	.text
_ft_list_sort:
	cmp		rdi,0
	jz		.OUT
	push	rbx			;cmp
	mov		rbx,rsi
	push	r12			;prev
	push	r13			;index
	push	r14			;insert
	push	r15			;insert_prev
	push	rdi			;lst_ref
	mov		r14,[rdi]
	cmp		rbx, 0
	jz		.OUT_6
.NEXT_INSERT:
	mov		r15,r14
	mov		r14,[r14+8]
	cmp		r14,0
	jz		.OUT_6
	mov		r12,[rsp]
	mov		r13,[r12]
.INSERTION_SEARCH:
	cmp		r13,r14
	jz		.NEXT_INSERT
	mov		rdi,[r13]
	mov		rsi,[r14]
	call	rbx
	cmp		rax,0
	jle		.NEXT_INDEX
	mov		rax,[r14+8]
	mov		[r15+8],rax
	mov		[r14+8],r13
	cmp		r12,[rsp]
	jnz		.NOT_FIRST
	mov		[r12],r14
	jmp		.NEXT_INSERT
.NOT_FIRST:
	mov		[r12+8],r14
	jmp		.NEXT_INSERT
.NEXT_INDEX:
	mov		r12,r13
	mov		r13,[r13+8]
	jmp		.INSERTION_SEARCH
.OUT_6:
	pop		rdi
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		rax
.OUT:
	ret
