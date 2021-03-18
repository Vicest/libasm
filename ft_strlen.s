	.globl _ft_strlen

_ft_strlen:
	movq	$-1,%rax		# i = -1
loop:
	addq	$1,%rax			# ++i
	cmpl	(%rdi,%rax),$0	# rdi[i] == 0
	jnz		loop
	ret
