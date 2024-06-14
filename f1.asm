section .data
factor: dd 0.6
term: dd 3.0


section .text
global f1
f1:
    finit
    fld dword [esp + 4]
    fld dword [factor]
    fmulp st1, st0
    
    fld dword [term]
    faddp st1, st0

    ret
