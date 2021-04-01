	global	_ft_strcmp
	section	.text
_ft_strcmp:
	mov		qword rdx,-1
.NEXT_CHAR:
	inc		rdx
	xor		rax,rax
	xor		rcx,rcx
	mov		al,[rdi+rdx]
	mov		cl,[rsi+rdx]
	cmp		byte al,0
	jz		.STR_END
	sub		 eax,ecx
	jz		.NEXT_CHAR
	ret
.STR_END:
	sub		 eax,ecx
	ret
