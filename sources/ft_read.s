	global	_ft_read
	section	.text
_ft_read:
	mov		rax,3
	push	16
	syscall

