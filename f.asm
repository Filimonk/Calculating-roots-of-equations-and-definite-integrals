section .data
factor_f1: dd 0.6
term_f1: dd 3.0

degree_f2: dd 3.0
term1_f2: dd -2.0
term2_f2: dd -1.0

divider_f3: dd 3.0


section .text

global f1
f1:
    finit
    fld dword [esp + 4]
    fld dword [factor_f1]
    fmulp
    
    fld dword [term_f1]
    faddp

    ret

global f2
f2:
    finit
    fld dword [esp + 4]
    fld dword [term1_f2]
    faddp
    
    ; возведем в степень 3 регистр st0
    fld st0
    fld st0
    fmulp
    fmulp
    
    fld dword [term2_f2]
    faddp

    ret

global f3
f3:
    finit
    fld dword [divider_f3]
    fld dword [esp + 4]
    fdivp

    ret
