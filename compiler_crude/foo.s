.globl foo
foo:
	mov %rdi, -8(%rsp)
	mov %rsi, -16(%rsp)

	mov -8(%rsp), %rax
	mov %rax, -88(%rsp)
	mov -16(%rsp), %rax
	neg %rax
	mov %rax, -96(%rsp)
	mov $42, %rax
	add -96(%rsp), %rax
	add -88(%rsp), %rax

	ret
