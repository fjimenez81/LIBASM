global _ft_strcpy

_ft_strcpy:
        mov rax, 0
        jmp cpy_str

cpy_str:
        cmp BYTE[rsi + rax], 0          ; rsi = str source
        je  exit
        mov cl, [rsi + rax]             ; copia src a cl , cl = registro de 8 bits
        mov [rdi + rax], cl             ; rdi = str destino, copia cx a dest como un swap
        inc rax
        jmp cpy_str

exit:
        mov cl, 0                       ; dest = '\0'
        mov [rdi + rax], cl             ; y vuelve hacerse swap a dest
        mov rax, rdi                    ; rax siempre contiene el valor de retorno
        ret