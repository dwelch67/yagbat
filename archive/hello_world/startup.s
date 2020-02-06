

    .code 32

.globl _start
_start:
    b start_vector

start_vector:
    ldr sp,=0x03007000
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

.globl GETSP
GETSP:
    mov r0,sp
    bx lr

