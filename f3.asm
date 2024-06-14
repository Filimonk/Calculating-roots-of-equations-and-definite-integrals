section .data
divider: dd 3.0


section .text
global f3
f3:
    finit
    fld dword [divider]
    fld dword [esp + 4]
    fdivp st1, st0

    ret
