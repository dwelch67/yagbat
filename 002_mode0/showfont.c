

#include <stdio.h>

#include "fontdata.h"


int main ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    for(rc=0;rc<256;rc++)
    {
        if(rc==1)
        {
            rc=0x30;
        }
        if(rc==0x3A)
        {
            rc='A';
        }
        if(rc=='G')
        {
            break;
        }
        ra=rc<<1;
        printf("0x%08X,",fontdata[ra+0]);
        printf("0x%08X,\n",fontdata[ra+1]);
    }

    return(0);
}
