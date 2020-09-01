global ft_read
extern	__errno_location

ft_read:
	mov rax, 0
    syscall
	cmp rax, 0
	jl	exit		; salta a error_exit si read no puede leer
	ret					

exit:
	neg		rax					;	Rax stores the negative value of the error code
	mov		rdx, rax			;	Rdx saves a copy of the error code
	call	__errno_location					; saca el valor de rdi fuera del stack
	mov [rax], rdi		; establece errno in rax
	mov rax, -1			; establece rax to -1
	ret					; return rax