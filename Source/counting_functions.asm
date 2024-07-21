section .text
global f1, f2, f3

f1:
    finit
    push ebp
    mov ebp, esp
    
    fld1
    push 2
    fild dword[esp]
    pop eax
    fdivp
    fld qword[ebp + 8]
    fld1
    faddp
    fdivp
    fld1
    faddp
    push 3
    fild dword[esp]
    pop eax
    fmulp
    
    mov esp, ebp
    pop ebp
    ret

f2:
    finit
    push ebp
    mov ebp, esp
    
    push 5
    fild dword[esp]
    pop eax
    push 2
    fild dword[esp]
    pop eax
    fdivp
    fld qword[ebp + 8]
    fmulp
    push 19
    fild dword[esp]
    pop eax
    push 2
    fild dword[esp]
    pop eax
    fdivp
    fsubp
    
    mov esp, ebp
    pop ebp
    ret

f3:
    finit
    push ebp
    mov ebp, esp
    
    push 5
    fild dword[esp]
    pop eax
    fld qword[ebp + 8]
    fdivp
    
    mov esp, ebp
    pop ebp
    ret
