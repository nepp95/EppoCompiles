section .text
	global _start

_start:
	mov eax, 60
	mov rdi, 5
	syscall
