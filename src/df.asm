section .data
factor_df1: dd 0.6

degree_df2: dd 2.0
term_df2: dd -2.0
factor_df2: dd 3.0

divider_df3: dd -3.0


section .text

global df1
df1:
    finit
    fld dword [factor_df1]

    ret

global df2
df2:
    finit
    fld dword [esp + 4]
    fld dword [term_df2]
    faddp
    
    ; возведем в степень 2 регистр st0
    fld st0
    fmulp
    
    fld dword [factor_df2]
    fmulp

    ret
    
global df3
df3:
    finit
    fld dword [divider_df3]
    fld dword [esp + 4]
    fld st0
    fmulp
    fdivp

    ret
