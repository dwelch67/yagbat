

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fontdata.h"

unsigned int ra;
unsigned int rb;
unsigned int rc;
unsigned int rd;
unsigned int re;

int main ( void )
{
    rd=sizeof(fontdata)/4;
    for(ra=0;ra<rd;ra++)
    {
        if((ra&1)==0)
        {
            printf("//---- %02X ----\n",ra>>1);
        }


        rc=fontdata[ra];
        re=fontdata[ra];

        for(rb=0;rb<8;rb++)
        {
            if(rc&0x80000000) printf("0x07,"); else printf("0x00,");
            rc<<=1;
        }
        printf(" //[");
        for(rb=0;rb<8;rb++)
        {
            if(re&0x80000000) printf("#"); else printf(" ");
            re<<=1;
        }
        printf("]\n");
        for(rb=0;rb<8;rb++)
        {
            if(rc&0x80000000) printf("0x07,"); else printf("0x00,");
            rc<<=1;
        }
        printf(" //[");
        for(rb=0;rb<8;rb++)
        {
            if(re&0x80000000) printf("#"); else printf(" ");
            re<<=1;
        }
        printf("]\n");
        for(rb=0;rb<8;rb++)
        {
            if(rc&0x80000000) printf("0x07,"); else printf("0x00,");
            rc<<=1;
        }
        printf(" //[");
        for(rb=0;rb<8;rb++)
        {
            if(re&0x80000000) printf("#"); else printf(" ");
            re<<=1;
        }
        printf("]\n");
        for(rb=0;rb<8;rb++)
        {
            if(rc&0x80000000) printf("0x07,"); else printf("0x00,");
            rc<<=1;
        }
        printf(" //[");
        for(rb=0;rb<8;rb++)
        {
            if(re&0x80000000) printf("#"); else printf(" ");
            re<<=1;
        }
        printf("]\n");
    }




    return(0);
}

