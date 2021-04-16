	global	_ft_list_remove_if
	extern	_free
	section	.text
_ft_list_remove_if:
	mov		r10,rdi
	cmp		r10,0
	jz		.OUT
	mov		rdi,[rdi]
	call	rdx
	jnz		.NEXT
	call	rcx
	call	_free


.OUT
	ret
