	global	_ft_create_elem
	extern	_malloc
	section	.text
_ft_create_elem:
	push	rdi
	mov		rdi,16
	call	_malloc
	cmp		rax,0
	jz		.MALLOC_NOMEM
	mov		rdi,[rsp]
	mov		[rax],rdi
	mov		qword [rax+8],0
.MALLOC_NOMEM:
	pop		rdi
	ret			;ENOMEM set by malloc
