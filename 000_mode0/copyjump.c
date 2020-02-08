
extern void PUT32 ( unsigned int, unsigned int );
extern void HOP ( unsigned int );
extern void faster_copy ( const unsigned int *, unsigned int, unsigned int );


#include "rom.h"

#define EWRAM 0x02000000

void notmain ( void )
{
    //unsigned int ra;
    //unsigned int rb;
    //unsigned int rc;
    //rb=EWRAM;
    //rc=0;
    //for(ra=0;ra<prog_len;ra++)
    //{
        //PUT32(rb,prog_data[rc++]); rb+=4;
    //}
    faster_copy(prog_data,EWRAM,prog_len);
    HOP(EWRAM);
}
