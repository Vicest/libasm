	global	_ft_isspace
	section	.text
_ft_isspace:
	cmp		dil,0x20
	jz		.RET_TRUE
	cmp		dil,0x09
	jl		.RET_FALSE
	cmp		dil,0x0d
	jg		.RET_FALSE
.RET_TRUE
	mov		eax,1
	ret
.RET_FALSE
	mov		eax,0
	ret
