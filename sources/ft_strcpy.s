	global	_ft_strcpy
	section	.text
_ft_strcpy:
	mov		qword rax,-1
NEXT_CHAR:
	inc		qword rax
	mov		rbx,[rsi+rax]
	mov		[rdi+rax],rbx
	cmp		byte [rsi+rax],0
	jnz		NEXT_CHAR
	add		rax,rdi
	retq
