global _ft_strlen       ;inicia la funcion

_ft_strlen:             ;llama a la funcion
        mov     rax, 0  ;pone la variable contador a 0
        jmp     while   ;salta a la funcion que hace el bucle

while:
        cmp         BYTE[rdi + rax], 0  ;hace la comparacion s[i] == 0
        je          exit                ;si es 0 salta a la funcion de escape y retorno 
        inc         rax                 ;incrementa en 1 el contador i++
        jmp         while               ;manda repetir el bucle

exit:
        ret     ;funcion de retorno y fin de la funcion