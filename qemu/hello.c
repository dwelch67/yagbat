
unsigned int GETPC ( void );
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
//-------------------------------------------------------------------------
void uart_putc ( unsigned int x )
{
    PUT32(0x101f1000,x);
}
//-------------------------------------------------------------------------
void hexstring ( unsigned int d )
{
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_putc(rc);
        if(rb==0) break;
    }
    uart_putc(0x0D);
    uart_putc(0x0A);
}

int notmain ( void )
{
    unsigned int ra;

    hexstring(GETPC());
    hexstring(0x12345678);
    for(ra=0;ra<0x20;ra+=4) hexstring(GET32(ra));
    return(0);
}
