global _ft_read

_ft_read:
	mov rax, 0x2000003 	; 0x2000003 para leer
    syscall				; llama a read
	jc	error_exit
	ret					

error_exit:
	mov rax, -1
	ret