.static
db MojePiwoHelloWorld "Hello World; Teapot 0.1"
; Begin of the code segment
.code
mov ax, @MojePiwoHelloWorld; Pass address of MojePiwoHelloWorld to ax
push ax
call TEAPrintFunction

