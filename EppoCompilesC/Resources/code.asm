section .text
    global _start
    
section .data
    string db 'Hello World!', 0

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, string
    mov edx, 13
    int 0x80

    ; Return 0;
    mov eax, 1
    xor ebx, ebx
    int 0x80