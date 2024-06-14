section .data
degree: dd 2.0

term: dd -2.0
factor: dd 3.0


section .text
global df2
df2:
    finit
    fld dword [esp + 4]
    fld dword [term]
    faddp ;st1, st0
    
    ; возведем в степень 2 регистр st0
    fld st0
    fmulp ;st1, st0
    
    fld dword [factor]
    fmulp ;st1, st0

    ret
