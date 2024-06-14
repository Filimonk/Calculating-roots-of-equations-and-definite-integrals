section .data
factor: dd 0.6


section .text
global df1
df1:
    finit
    fld dword [factor]

    ret
