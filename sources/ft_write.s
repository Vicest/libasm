	global	_ft_read
	extern ___error
	section	.text
_ft_read:
	mov		rax,0x2000004
	syscall
	jnc		.CLEAN
	push	rax
	call	___error
	pop		r10
	mov		[rax],r10
	mov		rax, -1
.CLEAN
	ret
