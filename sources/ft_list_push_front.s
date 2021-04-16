	global	_ft_list_push_front
	extern	_ft_create_elem
	section	.text
_ft_list_push_front:
	push	rdi
	cmp		rdi,0
	jz		.OUT
	mov		rdi,rsi
	call	_ft_create_elem
	cmp		rax,0
	jz		.OUT
	pop		rsi
	mov		rdx,[rsi]
	mov		[rsi],rax
	mov		[rax+8],rdx
	ret
.OUT:
	pop		rdi
	ret
