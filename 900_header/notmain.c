
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void PUT16 ( unsigned int, unsigned int );
extern unsigned int GET16 ( unsigned int );

#define DISPCNT 0x04000000
#define BG0CNT  0x04000008

#define PMEM 0x05000000
#define TMEM 0x06000000
#define VMEM 0x06008000

//#define TWIDE 32
//#define THIGH 20
//#define TVISIBLE 30

void notmain ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;

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
    ra=TMEM;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;
    PUT32(ra,0x00000000); ra+=4; PUT32(ra,0x00000000); ra+=4;

    PUT32(ra,0x01010000); ra+=4; PUT32(ra,0x01010000); ra+=4;
    PUT32(ra,0x01010000); ra+=4; PUT32(ra,0x01010000); ra+=4;
    PUT32(ra,0x01010000); ra+=4; PUT32(ra,0x01010000); ra+=4;
    PUT32(ra,0x01010000); ra+=4; PUT32(ra,0x01010000); ra+=4;
    PUT32(ra,0x00010001); ra+=4; PUT32(ra,0x00010001); ra+=4;
    PUT32(ra,0x01000100); ra+=4; PUT32(ra,0x01000100); ra+=4;
    PUT32(ra,0x00010001); ra+=4; PUT32(ra,0x00010001); ra+=4;
    PUT32(ra,0x01000100); ra+=4; PUT32(ra,0x01000100); ra+=4;

    PUT32(ra,0x02020000); ra+=4; PUT32(ra,0x02020000); ra+=4;
    PUT32(ra,0x02020000); ra+=4; PUT32(ra,0x02020000); ra+=4;
    PUT32(ra,0x02020000); ra+=4; PUT32(ra,0x02020000); ra+=4;
    PUT32(ra,0x02020000); ra+=4; PUT32(ra,0x02020000); ra+=4;
    PUT32(ra,0x00020002); ra+=4; PUT32(ra,0x00020002); ra+=4;
    PUT32(ra,0x02000200); ra+=4; PUT32(ra,0x02000200); ra+=4;
    PUT32(ra,0x00020002); ra+=4; PUT32(ra,0x00020002); ra+=4;
    PUT32(ra,0x02000200); ra+=4; PUT32(ra,0x02000200); ra+=4;

    PUT32(ra,0x03030000); ra+=4; PUT32(ra,0x03030000); ra+=4;
    PUT32(ra,0x03030000); ra+=4; PUT32(ra,0x03030000); ra+=4;
    PUT32(ra,0x03030000); ra+=4; PUT32(ra,0x03030000); ra+=4;
    PUT32(ra,0x03030000); ra+=4; PUT32(ra,0x03030000); ra+=4;
    PUT32(ra,0x00030003); ra+=4; PUT32(ra,0x00030003); ra+=4;
    PUT32(ra,0x03000300); ra+=4; PUT32(ra,0x03000300); ra+=4;
    PUT32(ra,0x00030003); ra+=4; PUT32(ra,0x00030003); ra+=4;
    PUT32(ra,0x03000300); ra+=4; PUT32(ra,0x03000300); ra+=4;

    PUT32(ra,0x04040000); ra+=4; PUT32(ra,0x04040000); ra+=4;
    PUT32(ra,0x04040000); ra+=4; PUT32(ra,0x04040000); ra+=4;
    PUT32(ra,0x04040000); ra+=4; PUT32(ra,0x04040000); ra+=4;
    PUT32(ra,0x04040000); ra+=4; PUT32(ra,0x04040000); ra+=4;
    PUT32(ra,0x00040004); ra+=4; PUT32(ra,0x00040004); ra+=4;
    PUT32(ra,0x04000400); ra+=4; PUT32(ra,0x04000400); ra+=4;
    PUT32(ra,0x00040004); ra+=4; PUT32(ra,0x00040004); ra+=4;
    PUT32(ra,0x04000400); ra+=4; PUT32(ra,0x04000400); ra+=4;

    PUT32(ra,0x05050000); ra+=4; PUT32(ra,0x05050000); ra+=4;
    PUT32(ra,0x05050000); ra+=4; PUT32(ra,0x05050000); ra+=4;
    PUT32(ra,0x05050000); ra+=4; PUT32(ra,0x05050000); ra+=4;
    PUT32(ra,0x05050000); ra+=4; PUT32(ra,0x05050000); ra+=4;
    PUT32(ra,0x00050005); ra+=4; PUT32(ra,0x00050005); ra+=4;
    PUT32(ra,0x05000500); ra+=4; PUT32(ra,0x05000500); ra+=4;
    PUT32(ra,0x00050005); ra+=4; PUT32(ra,0x00050005); ra+=4;
    PUT32(ra,0x05000500); ra+=4; PUT32(ra,0x05000500); ra+=4;

    PUT32(ra,0x06060000); ra+=4; PUT32(ra,0x06060000); ra+=4;
    PUT32(ra,0x06060000); ra+=4; PUT32(ra,0x06060000); ra+=4;
    PUT32(ra,0x06060000); ra+=4; PUT32(ra,0x06060000); ra+=4;
    PUT32(ra,0x06060000); ra+=4; PUT32(ra,0x06060000); ra+=4;
    PUT32(ra,0x00060006); ra+=4; PUT32(ra,0x00060006); ra+=4;
    PUT32(ra,0x06000600); ra+=4; PUT32(ra,0x06000600); ra+=4;
    PUT32(ra,0x00060006); ra+=4; PUT32(ra,0x00060006); ra+=4;
    PUT32(ra,0x06000600); ra+=4; PUT32(ra,0x06000600); ra+=4;

    PUT32(ra,0x07070000); ra+=4; PUT32(ra,0x07070000); ra+=4;
    PUT32(ra,0x07070000); ra+=4; PUT32(ra,0x07070000); ra+=4;
    PUT32(ra,0x07070000); ra+=4; PUT32(ra,0x07070000); ra+=4;
    PUT32(ra,0x07070000); ra+=4; PUT32(ra,0x07070000); ra+=4;
    PUT32(ra,0x00070007); ra+=4; PUT32(ra,0x00070007); ra+=4;
    PUT32(ra,0x07000700); ra+=4; PUT32(ra,0x07000700); ra+=4;
    PUT32(ra,0x00070007); ra+=4; PUT32(ra,0x00070007); ra+=4;
    PUT32(ra,0x07000700); ra+=4; PUT32(ra,0x07000700); ra+=4;

    //make screen black/clear screen
    ra=VMEM;
    for(rb=0;rb<(32*20);rb++)
    {
        PUT16(ra,0x0000);
        ra+=2;
    }
    //put some tiles on the screen
    ra=VMEM;
    for(rc=0,rb=0;rb<(32*10);rb++,rc++)
    {
        rc&=7;
        if(rc==0) rc=1;
        PUT16(ra,rc);
        ra+=2;
    }
}

