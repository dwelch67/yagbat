
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void PUT16 ( unsigned int, unsigned int );
extern unsigned int GET16 ( unsigned int );

#define DISPCNT 0x04000000
#define BG0CNT  0x04000008

#define PMEM 0x05000000
#define TMEM 0x06000000
#define VMEM 0x06008000

#include "hexfont.h"

unsigned short col;

static void hexstrings  ( unsigned int x )
{
    unsigned int ra;
    unsigned int rb;

    if(col==0)
    {
        rb=VMEM;
        for(ra=0;ra<32*19;ra++)
        {
            PUT16(rb,GET16(rb+64));
            rb+=2;
        }
        rb=VMEM+(19<<6);
        for(ra=0;ra<8;ra++)
        {
            PUT16(rb,((x>>28)&0xF)+1);
            x<<=4;
            rb+=2;
        }
        for(;ra<32;ra++)
        {
            PUT16(rb,0);
            rb+=2;
        }
        col+=8;
    }
    else
    {
        rb=VMEM+(19<<6);
        rb+=(col<<1);
        for(ra=0;ra<8;ra++)
        {
            if(col<29)
            {
                PUT16(rb,((x>>28)&0xF)+1);
                x<<=4;
                rb+=2;
                col++;
            }
        }
    }
    col++;
}

static void hexstring  ( unsigned int x )
{
    hexstrings(x);
    col=0;
}

static void vidsetup ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int off;
    unsigned int font;

    PUT16(DISPCNT,0x0100);
    PUT16( BG0CNT,0x1080);
    PUT16(PMEM+0x0,0x0000); //BLACK
    PUT16(PMEM+0x2,0x001F); //RED
    PUT16(PMEM+0x4,0x03E0); //GREEN
    PUT16(PMEM+0x6,0x03FF); //GREEN+RED
    PUT16(PMEM+0x8,0x7C00); //BLUE
    PUT16(PMEM+0xA,0x7C1F); //BLUE+RED
    PUT16(PMEM+0xC,0x7FE0); //BLUE+GREEN
    PUT16(PMEM+0xE,0x7FFF); //BLUE+GREEN+RED (WHITE)
    off=0;
    for(ra=0;ra<(17<<1);ra++)
    {
        font=fontdata[ra];
        for(rb=0;rb<(32>>1);rb++)
        {
            switch(font>>(32-2))
            {
                case 0: PUT16(TMEM+off,0x0000); break;
                case 1: PUT16(TMEM+off,0x0700); break;
                case 2: PUT16(TMEM+off,0x0007); break;
                case 3: PUT16(TMEM+off,0x0707); break;
            }
            off+=2;
            font<<=2;
        }
    }
    ra=VMEM;
    for(rb=0;rb<(32*20);rb++)
    {
        PUT16(ra,0x0000);
        ra+=2;
    }
    col = 0;
}

void notmain ( void )
{
    unsigned int ra;

    vidsetup();
    hexstring(0x12345678);
    for(ra=0;ra<10;ra++)
    {
        hexstring(ra);
    }
    for(ra=0;ra<10;ra++)
    {
        hexstrings(ra++);
        hexstring(ra);
    }
}
