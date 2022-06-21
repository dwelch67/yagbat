
.cpu arm7tdmi
.code 32

.globl _start
_start:
    ldr r0,=thumb_entry
    bx r0
.ltorg

.thumb
.thumb_func
thumb_entry:
    ldr r0,=0x03008000
    mov sp,r0
    bl notmain
hang:
    b hang

.globl PUT16
.thumb_func
PUT16:
    strh r1,[r0]
    bx lr

.globl GET16
.thumb_func
GET16:
    ldrh r0,[r0]
    bx lr

.globl PUT32
.thumb_func
PUT32:
    str r1,[r0]
    bx lr

.globl GET32
.thumb_func
GET32:
    ldr r0,[r0]
    bx lr
