	global	_ft_atoi_base
	section	.data

	section	.text
_ft_atoi_base:
	xor		rax,rax
	cmp		rdi,0
	mov		r10,-1
	jz		.DONE
.IS_SPACE:
	inc		r10
	cmp		byte [rdi + r10],0x20
	cmp		byte [rdi + r10],0x09
	jl		.IS_SIGN
	cmp		byte [rdi + r10],0x0d
	jle		.IS_SPACE
.IS_SIGN
	cmp:W

	


.DONE:
	ret
