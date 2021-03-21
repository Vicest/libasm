	global	_ft_strcmp
	section	.text
_ft_strcmp:
	mov		qword rbx,-1
NEXT_CHAR:
	inc		rbx
	xor		rax,rax
	mov		ah,[rdi+rbx]
	cmp		byte [rdi+rbx],0
	jz		STR_END
	cmp		ah,[rsi+rbx]
	jz		NEXT_CHAR
	sub		ah,[rsi+rbx]
	ret
STR_END:
	sub		ah,[rsi+rbx]
	ret
