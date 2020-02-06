
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fpin,*fpout;

char filename[1024];

unsigned int data[(256*1024)>>2];


int main ( int argc, char *argv[] )
{
    unsigned int ra,rb;

    if(argc<2)
    {
        printf("copyjump file.bin\n");
        return(1);
    }
    fpin=fopen(argv[1],"rb");
    if(fpin==NULL)
    {
        printf("Error opening file %s\n",argv[1]);
        return(1);
    }
    sprintf(filename,"%s.s",argv[1]);
    fpout=fopen(filename,"wt");
    if(fpout==NULL)
    {
        printf("Error creating file %s\n",filename);
        return(1);
    }

fprintf(fpout,"    .code 32\n");
fprintf(fpout,"\n");
fprintf(fpout,".globl _start\n");
fprintf(fpout,"_start:\n");
fprintf(fpout,"\n");
fprintf(fpout,"    b start_vector\n");
fprintf(fpout,"\n");


fprintf(fpout,"  @@@ Header definition pilfered from Jeff Frohwein's crt0\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Nintendo Logo Character Data (8000004h)\n");
fprintf(fpout,"\n");
fprintf(fpout,"        .byte 0x24, 0x0FF, 0x0AE, 0x51, 0x69, 0x9A\n");
fprintf(fpout,"        .byte 0x0A2, 0x21, 0x3D, 0x84, 0x82, 0x0A, 0x84, 0x0E4, 0x9, 0x0AD, 0x11\n");
fprintf(fpout,"        .byte 0x24, 0x8B, 0x98, 0x0C0, 0x81, 0x7F, 0x21, 0x0A3, 0x52, 0x0BE\n");
fprintf(fpout,"        .byte 0x19, 0x93, 0x9, 0x0CE, 0x20, 0x10, 0x46, 0x4A,0x4A, 0x0F8\n");
fprintf(fpout,"        .byte 0x27, 0x31, 0x0EC, 0x58, 0x0C7, 0x0E8, 0x33, 0x82, 0x0E3, 0x0CE\n");
fprintf(fpout,"        .byte 0x0BF, 0x85, 0x0F4, 0x0DF, 0x94, 0x0CE, 0x4B, 0x9, 0x0C1, 0x94\n");
fprintf(fpout,"        .byte 0x56, 0x8A, 0x0C0, 0x13, 0x72, 0x0A7, 0x0FC, 0x9F, 0x84, 0x4D\n");
fprintf(fpout,"        .byte 0x73, 0x0A3, 0x0CA, 0x9A, 0x61, 0x58, 0x97, 0x0A3, 0x27, 0x0FC\n");
fprintf(fpout,"        .byte 0x3, 0x98, 0x76, 0x23, 0x1D, 0x0C7, 0x61, 0x3, 0x4, 0x0AE, 0x56, 0x0BF\n");
fprintf(fpout,"        .byte 0x38, 0x84, 0, 0x40, 0x0A7, 0x0E, 0x0FD, 0x0FF, 0x52, 0x0FE\n");
fprintf(fpout,"        .byte 0x3, 0x6F, 0x95, 0x30, 0x0F1, 0x97, 0x0FB, 0x0C0, 0x85, 0x60, 0x0D6\n");
fprintf(fpout,"        .byte 0x80, 0x25, 0x0A9, 0x63, 0x0BE, 0x3, 0x1, 0x4E, 0x38, 0x0E2, 0x0F9\n");
fprintf(fpout,"        .byte 0x0A2, 0x34, 0x0FF, 0x0BB, 0x3E, 0x3, 0x44, 0x78, 0x0, 0x90, 0x0CB\n");
fprintf(fpout,"        .byte 0x88, 0x11, 0x3A, 0x94, 0x65, 0x0C0, 0x7C, 0x63, 0x87, 0x0F0\n");
fprintf(fpout,"        .byte 0x3C, 0x0AF, 0x0D6, 0x25, 0x0E4, 0x8B, 0x38, 0x0A, 0x0AC, 0x72\n");
fprintf(fpout,"        .byte 0x21, 0x0D4, 0x0F8, 0x7\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Game Title (80000A0h)\n");
fprintf(fpout,"        .byte   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00\n");
fprintf(fpout,"        .byte   0x00,0x00,0x00,0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Game Code (80000ACh)\n");
fprintf(fpout,"        .byte   0x00,0x00,0x00,0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Maker Code (80000B0h)\n");
fprintf(fpout,"        .byte   0x30,0x31\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Fixed Value (80000B2h)\n");
fprintf(fpout,"        .byte   0x96\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Main Unit Code (80000B3h)\n");
fprintf(fpout,"        .byte   0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Device Type (80000B4h)\n");
fprintf(fpout,"        .byte   0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Unused Data (7Byte) (80000B5h)\n");
fprintf(fpout,"        .byte   0x00,0x00,0x00,0x00,0x00,0x00,0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Software Version No (80000BCh)\n");
fprintf(fpout,"        .byte   0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Complement Check (80000BDh)\n");
fprintf(fpout,"        .byte   0xf0\n");
fprintf(fpout,"\n");
fprintf(fpout,"    @ Checksum (80000BEh)\n");
fprintf(fpout,"        .byte   0x00,0x00\n");
fprintf(fpout,"\n");
fprintf(fpout,"    .align\n");
fprintf(fpout,"\n");

fprintf(fpout,"start_vector:\n");
fprintf(fpout,"    ldr r0,program_start\n");
fprintf(fpout,"    ldr r1,program_dest\n");
fprintf(fpout,"    ldr r2,program_size\n");
fprintf(fpout,"copy_loop:\n");
fprintf(fpout,"    ldr r3,[r0],#4\n");
fprintf(fpout,"    str r3,[r1],#4\n");
fprintf(fpout,"    subs r2,r2,#1\n");
fprintf(fpout,"    bne copy_loop\n");
fprintf(fpout,"\n");
fprintf(fpout,"    ldr pc,program_dest\n");
fprintf(fpout,"\n");


    fprintf(fpout,"program_start: .word program_data\n");
    fprintf(fpout,"program_dest: .word 0x02000000\n");


    memset(data,0xFF,sizeof(data));
    rb=fread(data,1,sizeof(data),fpin);
    rb+=3;
    rb>>=2;
    fprintf(fpout,"program_size: .word 0x%08X\n",rb);
fprintf(fpout,"program_data:\n");
    for(ra=0;ra<rb;ra++)
    {
        fprintf(fpout,"    .word 0x%08X\n",data[ra]);
    }

    fclose(fpout);
    fclose(fpin);

    if(rb==0) return(1);
    return(0);
}


