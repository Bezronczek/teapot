.static
db MojePiwoHelloWorld "Hello World; Teapot 0.1"
.code
mov ax, @MojePiwoHelloWorld; Pass address of MojePiwoHelloWorld to ax
push ax
call TEAPrintFunction

