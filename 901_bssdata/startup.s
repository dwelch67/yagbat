
.cpu arm7tdmi
.code 32

.globl _start
_start:
    ldr sp,=0x03008000
    bl notmain
hang:
    b hang

.globl bounce
bounce:
    bx lr

.data
.byte 7

