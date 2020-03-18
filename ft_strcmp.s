global _ft_strcmp

_ft_strcmp:
        mov rcx , -1
        jmp str_cmp

str_cmp:
        inc rcx
        mov dl, BYTE[rdi + rcx]
        mov bl, BYTE[rsi + rcx]
        cmp BYTE[rdi + rcx], 0
        je  str_cmp
        cmp rbx, 0
        jl negativo
        cmp rbx, 0
        je exit
        sub rdx, rbx
        mov rax, rdx
        ret

negativo:
        sub rbx, rdx
        neg rbx
        mov rax, rbx
        ret

exit:
        mov rax, 0
        ret