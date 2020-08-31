global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc
extern ___error

;rdi = char *str

_ft_strdup:
        push rdi        ; ponemos rdi para apilar
        call _ft_strlen ; se llama a ft_strlen para dar valor a rax
        mov rdi, rax    ; mueve el valor de rax a rdi
        call _malloc    ; llama a malloc
        cmp rax, 0      ; revisa si hay error de malloc
        je error        ; si lo hay salta error
        pop rsi         ; saca la cadena que vas a duplicar
        mov rdi, rax    ; para meterla en rdi ya que ha reservado memoria
        call _ft_strcpy ; llama ft_strcpy para copiarla
        ret             ; retorna la cadena alocada en memoria

error:
        pop rdi         ; quita rdi de la memoria
        call ___error   ; llama error
        mov rdi, 12     ; 12 es numero de error de malloc en errno
        mov [rax], rdi  ; establece el valor de rdi dentro de rax
        mov rax, 0      ; estable rax a 0
        ret             ; retorna 0