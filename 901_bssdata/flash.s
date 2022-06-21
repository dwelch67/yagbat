
.cpu arm7tdmi
.code 32

/* address 0x08000000*/
rom_start:
    b ram_start
    .space 0xA0-0x04,0

/* address 0x080000A0*/
    .space 0xC0-0xA0,0

/* address 0x080000C0*/
ram_start:
    b _start
    .space 0xE0-0xC4,0

/*address 080000E0*/
.globl _start
_start:
    ldr sp,=0x03008000
    bl notmain
hang:
    b hang

.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.globl HOP
HOP:
    bx r0

.globl faster_copy
faster_copy:
    push {r4,r5,r6,r7}
    ldmia r0!,{r4,r5,r6,r7}
    stmia r1!,{r4,r5,r6,r7}
    subs r2,#4
    bne faster_copy
    pop {r4,r5,r6,r7}
    bx lr
