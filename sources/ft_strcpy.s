	global	_ft_strcpy
	section	.text
_ft_strcpy:
	mov		qword rax,-1
.NEXT_CHAR:
	inc		qword rax
	mov		rcx,[rsi+rax]
	mov		[rdi+rax],rcx
	cmp		byte [rsi+rax],0
	jnz		.NEXT_CHAR
	mov		rax,rdi
	retq
