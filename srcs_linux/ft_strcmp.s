global ft_strcmp

;rdi = s1 | rsi = s2

ft_strcmp:
        mov rcx, 0      ; iniciamos el contador
        mov rax, 0      ; inicia rax para el return
        mov rdx, 0
        jmp str_cmp     ; saltamos al bucle

str_cmp:
        mov dl, BYTE[rdi + rcx] ; mueve el caracter de rdi=s1 a dl: s1[i]
        mov al, BYTE[rsi + rcx] ; mueve el caracter de rsi=s2 a al: s2[i]
        cmp dl, 0               ; revisa si s1 ha terminado: s1[i] == '\0'
        je exit                 ; je = jump if is equal, si s1 es '\0' salta exit
        cmp dl, al              ; compara si son iguales dl y al: s1[i]==s2[i]
        je increment            ; rcx++
        jmp exit                ; si termina el bucle se sale

increment:
        inc rcx
        jmp str_cmp

exit:
        sub rdx, rax    ; sub: resta el valor de rax de rdx en rdx
        mov rax, rdx    ; y ahora lo que vale rdx es rax
        ret             ; return rax