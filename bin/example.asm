.static
MojePiwoHelloWorld: "Hello World; Teapot 0.1; Author: \"Rafal Czaja\";"
; Begin of the code segment
.code
	mov ax, @MojePiwoHelloWorld; Pass address of MojePiwoHelloWorld to ax
	push ax
	call @TEAPrintFunction
	pop ax ; Get result from stack
	mov bx, 0
	cmp ax, bx
	jne @failedToPrint

.failedToPrint
	push ax
	mov ax, 0x0h ; exit function
	int 0x01h ; call to kernel

.float;Instruction for FPU
	mov fax, 0.1
.numberTest
	mov ecx, 1000

.hexTest
	jmp 0x10h

