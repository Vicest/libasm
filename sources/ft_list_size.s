	global	_ft_list_size
	section	.text
_ft_list_size:
	mov		rax,0
.NEXT:
	cmp		rdi,0
	jz		.DONE
	inc		rax
	mov		rdi,[rdi]
	jmp		.NEXT
.DONE:
	ret
