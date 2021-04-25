	global	_ft_strchr
	section	.text
.NEXT_CHAR:
	inc		rdi
_ft_strchr:
	xor		rax,rax
	cmp		byte [rdi],0
	jz		.NOT_FOUND
	cmp		byte [rdi],rsi
	jnz		.NEXT_CHAR
	mov		rdi,rax
.NOT_FOUND:
	retq
