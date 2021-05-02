	global	_ft_strchr
	section	.text
.NEXT_CHAR:
	inc		rdi
_ft_strchr:
	cmp		byte [rdi],0
	jz		.NOT_FOUND
	cmp		byte [rdi],sil
	jnz		.NEXT_CHAR
	mov		rax,rdi
	retq
.NOT_FOUND:
	xor		rax,rax
	retq
