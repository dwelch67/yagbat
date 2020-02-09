
.cpu arm7tdmi
.code 32

.globl _start
_start:
    ldr sp,=0x03008000
    bl notmain
hang:
    b hang

.globl PUT16
PUT16:
    strh r1,[r0]
    bx lr

.globl GET16
GET16:
    ldrh r0,[r0]
    bx lr

.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.globl GET32
GET32:
    ldr r0,[r0]
    bx lr
