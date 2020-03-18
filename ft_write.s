global _ft_write

; ft_write (rdi = [argv[0]] | rsi = [argv[1]] | rdx = [argv[2]])

_ft_write:
	mov	rax, 0x2000004	; 0x2000004 pala escribir
    syscall				; llama a write
	jc	error_exit
	ret					

error_exit:
	mov rax, -1,
	ret