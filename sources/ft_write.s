	global	_ft_read
	section	.text
_ft_read:
	mov		rax,0x2000004
	syscall
	ret
