
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
unsigned int GETPC ( void );
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void DOSWI ( void );
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void tuart_putc ( unsigned int x );
void hexstring ( unsigned int d );
//-------------------------------------------------------------------------
void uart_putc ( unsigned int x )
{
    PUT32(0x101f1000,x);
}
//-------------------------------------------------------------------------
void swi_code ( unsigned int inst, unsigned int sp )
{
    hexstring(inst);
    hexstring(sp);
    hexstring(GET32(sp+0x0));
    hexstring(GET32(sp+0x4));
    hexstring(GET32(sp+0x8));
}
//-------------------------------------------------------------------------
int notmain ( void )
{
    unsigned int ra;

    hexstring(GETPC());
    hexstring(0x12345678);
    for(ra=0;ra<0x20;ra+=4) hexstring(GET32(ra));
    PUT32(0x0000,0x1234);
    PUT32(0x0004,0x5768);
    hexstring(GET32(0x0000));
    hexstring(GET32(0x0004));

    for(ra=0x00;ra<0x20;ra+=4) PUT32(ra,GET32(0x10000+ra));
    for(ra=0;ra<0x20;ra+=4) hexstring(GET32(ra));

    DOSWI();
    hexstring(0x11223344);

    return(0);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
