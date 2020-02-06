

    .code 32

.globl _start
_start:
    b start_vector

 /*.byte 46,0,0,234*/
 .byte 36,255,174,81,105,154,162,33,61,132,130,10
 .byte 132,228,9,173,17,36,139,152,192,129,127,33,163,82,190,25
 .byte 147,9,206,32,16,70,74,74,248,39,49,236,88,199,232,51
 .byte 130,227,206,191,133,244,223,148,206,75,9,193,148,86,138,192
 .byte 19,114,167,252,159,132,77,115,163,202,154,97,88,151,163,39
 .byte 252,3,152,118,35,29,199,97,3,4,174,86,191,56,132,0
 .byte 64,167,14,253,255,82,254,3,111,149,48,241,151,251,192,133
 .byte 96,214,128,37,169,99,190,3,1,78,56,226,249,162,52,255
 .byte 187,62,3,68,120,0,144,203,136,17,58,148,101,192,124,99
 .byte 135,240,60,175,214,37,228,139,56,10,172,114,33,212,248,7
 .byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,48,49,150,0,0,0,0,0
 .byte 0,0,0,0,0,240,0,0


start_vector:
    ldr sp,=0x03007000

    mov r0, #31
    str r0, [r1] ;@ seems a bit scary but without this it doesnt work.

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

.globl GET32
GET32:
    ldr r0,[r0]
    bx lr

.globl STOP
STOP:
    b STOP

.globl GETSP
GETSP:
    mov r0,sp
    bx lr

.globl ASMDELAY
ASMDELAY:
    subs r0,#1
    bne ASMDELAY
    bx lr
