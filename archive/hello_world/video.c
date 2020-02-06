

unsigned short GET16 ( unsigned int );
void PUT16 ( unsigned int , unsigned short );
//#define PUT16(x,y) __asm__ __volatile__ ("strh %[result], [%[value]]" : : [result] "r" (y), [value] "r" (x) : "memory" );

#include "fontdata.h"

#define DISPCNT 0x04000000
#define BG0CNT  0x04000008

#define PMEM 0x05000000
#define VMEM 0x06000000
#define TMEM 0x06008000

#define TWIDE 32
#define THIGH 20
#define TVISIBLE 30

unsigned short col;

void hmemset ( unsigned int d, unsigned short s, unsigned int len )
{
    len>>=1;
    while(len--)
    {
        PUT16(d,s);
        d+=2;
    }
}

void hmemmove ( unsigned int d, unsigned int s, unsigned int len )
{
    len>>=1;
    while(len--)
    {
        PUT16(d,GET16(s));
        d+=2;
        s+=2;
    }
}

void initvideo ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int off;
    unsigned int font;

    PUT16(DISPCNT,0x0100);
    PUT16( BG0CNT,0x1080);

    PUT16(PMEM+0x0,0x0000);
    PUT16(PMEM+0x2,0x001F);
    PUT16(PMEM+0x4,0x03E0);
    PUT16(PMEM+0x6,0x03FF);
    PUT16(PMEM+0x8,0x7C00);
    PUT16(PMEM+0xA,0x7C1F);
    PUT16(PMEM+0xC,0x7FE0);
    PUT16(PMEM+0xE,0x7FFF);

    off=0;
    for(ra=0;ra<(256<<1);ra++)
    {
        font=fontdata[ra];
        for(rb=0;rb<(32>>1);rb++)
        {
            switch(font>>(32-2))
            {
                case 0: PUT16(VMEM+off,0x0000); break;
                case 1: PUT16(VMEM+off,0x0700); break;
                case 2: PUT16(VMEM+off,0x0007); break;
                case 3: PUT16(VMEM+off,0x0707); break;
            }
            off+=2;
            font<<=2;
        }
    }

    hmemset(TMEM,0,(TWIDE*THIGH)<<1);

    col=0;
}

void pushup ( void )
{
    hmemmove(TMEM,TMEM+(TWIDE<<1),(TWIDE*(THIGH-1))<<1);
    hmemset(TMEM+((TWIDE*(THIGH-1))<<1),0,TWIDE<<1);
    col=0;
}

void vidbyte ( unsigned char x )
{
    if(x<' ')
    {
        if(x==0x0D) col=0;
        if(x==0x0A) pushup();
    }
    else
    {
        if(col>=TVISIBLE) pushup();
        PUT16(TMEM+((TWIDE*(THIGH-1))<<1)+(col<<1),x);
        col++;
    }
}

void vidstring ( unsigned char *s )
{
    while(*s)
    {
        vidbyte(*s);
        s++;
    }
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
        vidbyte(rc);
        if(rb==0) break;
    }
    vidbyte(0x0D);
    vidbyte(0x0A);
}

