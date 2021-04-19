	global	_ft_list_remove_if
	extern	_free
	section	.text
_ft_list_remove_if:
	cmp		rdi,0
	jz		.OUT
	push	r12
	push	rbx
	push	r13
	push	r14
	push	r15
	mov		r12,rdi		;**bgn_lst
	mov		rbx,[rdi]	;*bgn_lst
	mov		r13,rdx		;cmp
	mov		r14,rcx		;free_fct
	mov		r15,rsi		;data_ref
.HEAD_LOOP:
	cmp		rbx,0
	jz		.OUT_5
	mov		rsi,r15
	mov		rdi,[rbx]
	call	r13
	cmp		rax,0
	jnz		.TAIL_LOOP
	mov		rdi,[rbx]
	call	r14
	mov		rdi,rbx
	mov		rbx,[rbx+8]
	mov		[r12],rbx
	call	_free
	jmp		.HEAD_LOOP
.TAIL_LOOP:
	cmp		qword [rbx+8],0
	jz		.OUT_5
	mov		r12,rbx
	mov		rbx,[rbx+8]
	mov		rsi,r15
	mov		rdi,[rbx]
	call	r13
	cmp		rax,0
	jnz		.TAIL_LOOP
	mov		rdi,[rbx]
	call	r14
	mov		rdi,rbx
	mov		rbx,[rbx+8]
	mov		[r12+8],rbx
	mov		rbx,r12
	call	_free
	jmp		.TAIL_LOOP
.OUT_5:
	pop		r15
	pop		r14
	pop		r13
	pop		rbx
	pop		r12
.OUT:
	ret
