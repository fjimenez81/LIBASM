global ft_strcpy

;rdi = dest | rsi = source

ft_strcpy:
        mov rax, 0                      ;inicia el contador
        mov rcx, 0                      ;inicia el contador
        jmp cpy_str

cpy_str:
        mov dl, byte[rsi + rcx]             ; copia src a cl , cl = registro de 8 bits
        mov byte[rdi + rcx], dl             ; rdi = str destino, copia cl a dest como un swap
        cmp dl, 0                           ; revisa si src ha terminado
        jne increment                        ; i++
        jmp exit

increment:
        inc rcx
        jmp cpy_str

exit:
        ;mov dl, 0                       ; dest = '\0'
        ;mov [rdi + rax], dl             ; y vuelve hacerse swap a dest
        mov rax, rdi                    ; rax siempre contiene el valor de retorno
        ret                             ; return rax