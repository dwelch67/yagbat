

    .code 32

.globl _start
_start:
    ldr pc,start_vector_add
    ldr pc,undef_vector_add
    ldr pc,swi_vector_add


start_vector_add: .word start_vector
undef_vector_add: .word undef_vector
swi_vector_add: .word swi_vector


start_vector:
    mov sp,#0x20000
    bl notmain
hang:
    b hang

undef_vector:
    b .

swi_vector:
    push {lr}
    ldr r0,[lr,#-4]
    mov r1,sp
    bl swi_code
    pop {lr}
    movs pc,lr

.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.globl GETPC
GETPC:
    mov r0,pc
    bx lr

.globl PUT16
PUT16:
    strh r1,[r0]
    bx lr

.globl GET32
GET32:
    ldr r0,[r0]
    bx lr


.globl GET16
GET16:
    ldrh r0,[r0]
    bx lr

.globl GETSP
GETSP:
    mov r0,sp
    bx lr

.globl DOSWI
DOSWI:
    push {lr}
    swi 0x123
    pop {lr}
    bx lr
