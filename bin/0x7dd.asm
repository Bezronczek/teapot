.code
	mov eax, 666
	mov ebx, 665
	cmp  eax, ebx
	je @RightResult
	jne @WrongResult

RightResult:
; do nothing

WrongResult:
; do much more nothing

.static
	TEAWelcome: "HelloWorld; First review;"
