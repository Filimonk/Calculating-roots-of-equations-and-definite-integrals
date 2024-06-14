section .data
degree: dd 3.0

term1: dd -2.0
term2: dd -1.0


section .text
global f2
f2:
    finit
    fld dword [esp + 4]
    fld dword [term1]
    faddp ;st1, st0
    
    ; возведем в степень 3 регистр st0
    fld st0
    fld st0
    fmulp ;st1, st0
    fmulp ;st1, st0
    
    fld dword [term2]
    faddp ;st1, st0

    ret
