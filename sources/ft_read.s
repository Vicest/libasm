	global	_ft_read
	extern ___error
	section	.text
_ft_read:
	mov		rax,0x2000003
	syscall
	cmp		rax,-1
	jnz		.OUT

	
.OUT:
	ret
