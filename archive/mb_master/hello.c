
#include "video.h"

void STOP ( void );
unsigned int GET32 ( unsigned int );
unsigned int GET16 ( unsigned int );
void PUT16 ( unsigned int, unsigned int );
void ASMDELAY ( unsigned int );
void hexstring ( unsigned int );
void hexstringr ( unsigned int );

#define RCNT    0x04000134
#define SIOCNT  0x04000128
#define SIOMULTI0 0X04000120
#define SIOMULTI1 0X04000122
#define SIOMULTI2 0X04000124
#define SIOMULTI3 0X04000126
#define SIOMULTSEND 0x0400012A

#define ClientLength 0x2000

unsigned int xfer ( unsigned int x )
{
    unsigned int ra;

    PUT16(SIOMULTSEND,x);
    PUT16(SIOCNT,0x208B);
    while(1)
    {
        ra=GET16(SIOCNT);
        if((ra&0x80)==0) break;
    }
    return(GET16(SIOMULTI1));
}


int notmain ( void )
{
    unsigned int ra;
    unsigned int rb;

    unsigned int bit;
    unsigned int data32;
    unsigned int var_30;
    unsigned int client_pos;
    unsigned int send_data16;
    unsigned int encrypt_seed;
    unsigned int send_data16_high;
    unsigned int var_C;
    unsigned int CRCTemp;
    unsigned char var_1;
    unsigned char var_8;

    initvideo();

    ra=GET16(SIOCNT);
    hexstring(ra);
    if((ra&0x3000)==0x2000)
    {
        if(ra&0x0030)
        {
            //I am a dependent
            hexstring(0x12341234);
            while(1)
            {
                ra=GET16(0x04000130);
                ra=~ra;
                ra&=0x03FF;
                hexstringr(ra);
            }
        }

    }
    //I am the master
    while(1)
    {
        ra=GET16(0x04000130);
        ra=~ra;
        ra&=0x03FF;
        hexstringr(ra);
        if(ra&1) break;
    }

    PUT16(RCNT,0x0000);
    PUT16(SIOCNT,0x2003);
    while(1)
    {
        rb=GET16(SIOCNT);
        if(rb==0x200B) break;
    }
    hexstring(rb);
    while(1)
    {
        rb=xfer(0x6202);
        hexstring(rb);
        if(rb==0x7202) break;
        ASMDELAY(0x10000);
    }
    rb=xfer(0x6100);
    hexstring(rb);

    for(ra=0x00;ra<0xC0;ra+=4)
    {
        rb=GET32(0x02000000+ra);
        xfer((rb>> 0)&0xFFFF);
        xfer((rb>>16)&0xFFFF);
    }

    rb=xfer(0x6202);
    hexstring(rb);
    rb=xfer(0x63C1);
    hexstring(rb);
    rb=xfer(0x63C1);
    hexstring(rb);


    encrypt_seed = ((rb&0x0FF)<<8)|0x0FFFF00C1;
    var_1 = (rb&0x0FF)+0x20F;
    rb = xfer((var_1 & 0x000000FF)|0x00006400);
    hexstring(rb);

    ASMDELAY(0x2000);

    rb = xfer( ( (ClientLength-0xC0) >> 2 ) - 0x34 );
    hexstring(rb);

    var_8 = rb;
    var_C = 0x0FFF8;

    send_data16_high = 0;

    client_pos = 0x0C0;

    while(client_pos<ClientLength)
    {
        data32=GET32(0x02000000+client_pos);
        CRCTemp = data32;
        for (bit = 0; bit <= 31; bit++)
        {
            var_30 = var_C^CRCTemp;
            var_C = var_C >> 1;
            CRCTemp = CRCTemp >> 1;
            if (var_30&0x01) var_C = var_C^0x0A517;
        }
        encrypt_seed = (encrypt_seed * 0x6F646573)+1;
        send_data16 = (encrypt_seed ^ data32) ^( (~(client_pos+0x2000000)+1) ^ 0x6465646F);
        send_data16_high = send_data16 >> 16;
        send_data16 = send_data16&0x0FFFF;
        rb = xfer(send_data16);
        if(rb!=client_pos)
        {
            hexstring(rb);
            hexstring(client_pos);
            hexstring(0x01BADBAD);
            return(1);
        }
        rb = xfer(send_data16_high);
        client_pos+=4;
    }
    send_data16 = 0x0065;
    rb = xfer(send_data16);
    hexstring(rb);
    rb = xfer(send_data16);
    hexstring(rb);
    while (rb != 0x0075) rb = xfer(send_data16);
    hexstring(rb);
    send_data16 = 0x0066;
    rb = xfer(send_data16);
    hexstring(rb);

    hexstring(var_8);
    hexstring(var_1);

    data32 = var_8;
    data32 <<= 8;
    data32 |= var_1;
    data32 |= 0xFFFF0000;
    hexstring(data32);
    for (bit = 0 ; bit<=31 ; bit++)
    {
        var_30 = var_C ^ data32;
        var_C  = var_C>>1;
        data32 = data32>>1;
        if (var_30 & 0x01) var_C = var_C ^ 0x0A517;
    }
    rb = xfer(var_C);
    hexstring(rb);
    if (var_C != rb)
    {
        hexstring(0x02BADBAD);
        return 1;
    }
    hexstring(0x12345678);
    return(0);
}
