global ft_strcmp

;rdi = s1 | rsi = s2

ft_strcmp:
	mov	rbx, 0
	mov 	rax, 0
	mov	cx, 0
	mov	dx, 0

compare:
	mov	cl, [rdi+rbx]		; mueve el caracter de rdi=s1 a cl: s1[i]
	mov	dl, [rsi+rbx]           ; mueve el caracter de rsi=s2 a dl: s2[i]
        cmp     cl, 0                   ; revisa si s1 ha terminado: s1[i] == '\0'
        jne      exit
        cmp     dl, 0                  
        je      exit		         ; je = jump if is equal, si s1 es '\0' salta exit
	cmp	cl, dl			; compara si son iguales dl y al: s1[i]==s2[i]
	jne	exit			;	Finish if they are not equal
	inc	rbx				;	Advance the pointer
	jmp	compare			;	Loop

exit:
	sub	cx, dx
	jl	negative		;	If *s1 > *s2 we return -1
	ja	positive		;	If *s1 < *s2 we return 1
	jmp	equal			;	If s1 == s2 we return 0

negative:
	mov	rax, -1
	ret

positive:
	mov	ax, cx
	ret

equal:
	mov	rax, 0
	ret