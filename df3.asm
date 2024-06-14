section .data
divider: dd -3.0


section .text
global df3
df3:
    finit
    fld dword [divider]
    fld dword [esp + 4]
    fld st0
    fmulp ;st1, st0
    fdivp ;st1, st0

    ret
