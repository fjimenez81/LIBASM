global _ft_write
extern	___error

; ft_write (rdi = [argv[0]] | rsi = [argv[1]] | rdx = [argv[2]])

_ft_write:
	mov rax, 0x2000004 	; pone la clave de lectura en rax
    syscall				; llama a read
	jc	error_exit		; salta a error_exit si read no puede leer
	ret					

error_exit:
	mov rdi, rax		; establece errno in rdi
	push rdi			; pone el valor de rdi encima del stack
	call ___error		; adquiere direccion de memoria de errno en rax
	pop rdi				; saca el valor de rdi fuera del stack
	mov [rax], rdi		; establece errno in rax
	mov rax, -1			; establece rax to -1
	ret					; return rax