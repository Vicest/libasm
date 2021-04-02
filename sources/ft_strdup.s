	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy
	section	.text
_ft_strdup:
	call	_ft_strlen
	push	rdi
	inc		rax
	mov		rdi,rax
	call	_malloc
	cmp		rax,0
	jz		.MALLOC_NOMEM
	pop		rsi
	mov		rdi,rax
	call	_ft_strcpy
.MALLOC_NOMEM:
	ret			;ENOMEM set by malloc


