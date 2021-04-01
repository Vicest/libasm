	global	_ft_strlen
	section	.text
_ft_strlen:
	mov		qword rax,-1
.NEXT_CHAR:
	inc		qword rax
	cmp		byte [rdi+rax],0
	jnz		.NEXT_CHAR
	retq
