
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void PUT16 ( unsigned int, unsigned int );
extern unsigned int GET16 ( unsigned int );

#define DISPCNT 0x04000000
#define BG0CNT  0x04000008

#define PMEM 0x05000000
#define TMEM 0x06000000
#define VMEM 0x06008000

#include "fontdata.h"

//#define TWIDE 32
//#define THIGH 20
//#define TVISIBLE 30

void notmain ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int off;
    unsigned int font;

    //display control,
    //mode 0
    //enable BG0
    PUT16(DISPCNT,0x0100);
    //BG0 control
    //256 color palette
    //tiles defined at 0x60000000
    //screen at 0x60008000
    PUT16( BG0CNT,0x1080);
    //setup the first 8 colors
    PUT16(PMEM+0x0,0x0000); //BLACK
    PUT16(PMEM+0x2,0x001F); //RED
    PUT16(PMEM+0x4,0x03E0); //GREEN
    PUT16(PMEM+0x6,0x03FF); //GREEN+RED
    PUT16(PMEM+0x8,0x7C00); //BLUE
    PUT16(PMEM+0xA,0x7C1F); //BLUE+RED
    PUT16(PMEM+0xC,0x7FE0); //BLUE+GREEN
    PUT16(PMEM+0xE,0x7FFF); //BLUE+GREEN+RED (WHITE)
    //lets make a few tiles 64 bytes per tile.

    off=0;
    for(ra=0;ra<(256<<1);ra++)
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

    //make screen black/clear screen
    ra=VMEM;
    for(rb=0;rb<(32*20);rb++)
    {
        PUT16(ra,0x0000);
        ra+=2;
    }
    //put some tiles on the screen
    off=VMEM;
    for(ra=0;ra<256;)
    {
        for(rb=0;(rb<30)&&(ra<256);rb++)
        {
            PUT16(off,ra++);
            off+=2;
        }
        off+=2;
        off+=2;
    }
}

