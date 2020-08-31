global ft_write
extern	__errno_location

; ft_write (rdi = [argv[0]] | rsi = [argv[1]] | rdx = [argv[2]])

ft_write:
	mov rax, 1 	; pone la clave de lectura en rax
    syscall
	cmp rax, 0				; llama a read
	jl	error_exit		; salta a error_exit si read no puede leer
	ret					

error_exit:
	neg  rax		; establece errno in rdi
	mov rdx, rax			; pone el valor de rdi encima del stack
	call __errno_location		; adquiere direccion de memoria de errno en rax
	mov [rax], rdx		; establece errno in rax
	mov rax, -1			; establece rax to -1
	ret					; return rax