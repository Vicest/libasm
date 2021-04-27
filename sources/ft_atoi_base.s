	global	_ft_atoi_base
	extern	_ft_isspace
	extern	_ft_strchr

	section	.text
_ft_atoi_base:
	cmp		rdi,0
	jz		.DONE_ERROR
	cmp		rsi,0
	jz		.DONE_ERROR
	cmp		byte [rsi],0
	jz		.DONE_ERROR
	cmp		byte [rsi+1],0
	jz		.DONE_ERROR
	;base_validation
	mov		r11,rdi		;*base_iter -> base_len
	mov		r10,rdi		;*base -> outval
	mov		r9,rsi		;*str bkp
.NEXT_BASE_CHAR:
	mov		byte rdi,[r11]
	cmp		rdi,0x2b
	jz		.DONE_ERROR
	cmp		rdi,0x2d
	jz		.DONE_ERROR
	call	_ft_isspace
	cmp		rax,0
	jz		.DONE_ERROR
	mov		byte rsi,rdi
	inc		r11
	mov		rsi,r11
	call	_ft_strchr
	cmp		rax,0
	jnz		.DONE_ERROR
	;assignment proper
	sub		r11,r10		;base_len
.SKIP_SPACES
	mov		rdi,[r9]
	inc		r9
	call	_ft_isspace
	cmp		rax,0
	jz		.SKIP_SPACES
.SIGN_MNGMNT
	mov		rdi,[r9]
	inc		r9
	cmp		rdi,0x2b
	jz		.SIGN_MNGMNT
	cmp		rdi,0x2d
	jnz		.ASSIGN


.DONE_ERROR:
	xor		r11,r11
.DONE:
	mov		rax,r11
	ret
