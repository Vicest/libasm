	global	_ft_strcpy
	section	.text
_ft_strcpy:
	mov		qword rax,-1
.NEXT_CHAR:
	inc		qword rax
	mov		byte ch,[rsi+rax]
	mov		byte [rdi+rax],ch
	cmp		byte [rsi+rax],0
	jnz		.NEXT_CHAR
	mov		rax,rdi
	retq
