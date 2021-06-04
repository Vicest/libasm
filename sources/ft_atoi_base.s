	global	_ft_atoi_base
	extern	_ft_isspace
	extern	_ft_strchr

	section	.text
_ft_atoi_base:
	cmp		rdi,0
	jz		.ERROR
	cmp		rsi,0
	jz		.ERROR
	cmp		byte [rsi],0
	jz		.ERROR
	cmp		byte [rsi+1],0
	jz		.ERROR
	push	rbx
	push	r12
	push	r13
	push	r14
	push	rsi
	;base_validation
	mov		r12,rsi		;*base_iter
	mov		r13,rdi		;*str
	xor		r14,r14		;sign_flg
.NEXT_BASE_CHAR:
	mov		byte dil,[r12]
	cmp		dil,0x2b
	jz		.ERROR_5
	cmp		dil,0x2d
	jz		.ERROR_5
	call	_ft_isspace
	cmp		rax,0
	jnz		.ERROR_5
	mov		byte sil,[r12]
	inc		r12
	mov		rdi,r12
	call	_ft_strchr
	cmp		rax,0
	jnz		.ERROR_5
	cmp		byte [r12],0
	jnz		.NEXT_BASE_CHAR
	;assignment proper
	sub		r12,[rsp]	;base_len
	mov		rbx,0		;outval
.SKIP_SPACES:
	mov		byte dil,[r13]
	call	_ft_isspace
	cmp		rax,0
	jz		.SIGN_MNGMNT
	inc		r13
	jmp		.SKIP_SPACES
.NEXT_SIGN:
	inc		r13
.SIGN_MNGMNT:
	mov		byte dil,[r13]
	cmp		dil,0x2b
	jz		.NEXT_SIGN
	cmp		dil,0x2d
	jnz		.NEXT_DIGIT
	xor		r14,0x1
	jmp		.NEXT_SIGN
.NEXT_DIGIT:
	xor		rsi,rsi
	mov		byte sil,[r13]
	mov		rdi,[rsp]
	call	_ft_strchr
	sub		rax,[rsp]
	jl		.STR_END
	push	rax
	mov		rax,r12
	mul		rbx
	mov		rbx,rax
	pop		rax
	add		rbx,rax
	inc		r13
	jmp		.NEXT_DIGIT
.STR_END:
	mov		rax,rbx
	cmp		r14,0
	jz		.DONE
	not		rax
	inc		rax
.DONE:
	pop		rdi
	pop		r14
	pop		r13
	pop		r12
	pop		rbx
	ret


.ERROR_5:
	xor		rax,rax
	jmp		.DONE
.ERROR:
	xor		rax,rax
	ret
