	global	_ft_isspace
	section	.text
_ft_isspace:
	cmp		edi,0x20
	jz		.RET_TRUE
	cmp		edi,0x11
	jl		.RET_FALSE
	cmp		edi,0x15
	jg		.RET_FALSE
.RET_TRUE
	mov		eax,1
	ret
.RET_FALSE
	mov		eax,0
	ret
