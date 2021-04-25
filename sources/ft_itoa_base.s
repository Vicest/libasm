	global	_ft_atoi_base
	section	.text
_ft_atoi_base:
	push	r15		;i
	push	r14		;base
	push	
.BASE_VERIF:
	mov		r15,-1
.NEXT_CHAR:
	inc		r15
	cmp		byte [rdi+r15],0x20
	jz		.BASE_ERROR
	cmp		byte [rdi+r15],0x2b
	jz		.BASE_ERROR
	cmp		byte [rdi+r15],0x2d
	jz		.BASE_ERROR

	;DO ME FULLY

	mov		eax,0
	mov		eax,0x80000000
.SIGN_READ



