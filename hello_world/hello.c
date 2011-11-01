
#include "video.h"

const char hello[]="Hello World!\r\n";

unsigned int GETSP ( void );
void hexstring ( unsigned int );

int notmain ( void )
{
    initvideo();
    vidstring((unsigned char *)hello);
    hexstring(GETSP());
    hexstring(0x12345678);
    return(0);
}
