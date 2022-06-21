
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int data[(256*1024)>>2];

int main ( int argc, char *argv[] )
{
    unsigned int ra,rb;
    unsigned int len;
    FILE *fp;


    if(argc<3)
    {
        printf("bintoc input.bin output.c\n");
        return(1);
    }
    fp=fopen(argv[1],"rb");
    if(fp==NULL)
    {
        printf("Error opening file %s\n",argv[1]);
        return(1);
    }
    memset(data,0xFF,sizeof(data));
    len=fread(data,1,sizeof(data),fp);
    printf("read %u bytes\n",len);
    fclose(fp);

    if(len<sizeof(data))
    {
        len+=31;
        len>>=5;
        len<<=3;
        if((len<<2)>sizeof(data)) len=sizeof(data)>>2;
    }

    fp=fopen(argv[2],"wt");
    if(fp==NULL)
    {
        printf("Error creating file %s\n",argv[2]);
        return(1);
    }
    fprintf(fp,"\n");
    fprintf(fp,"const unsigned int prog_len = %u; //0x%08X\n",len,len);
    fprintf(fp,"const unsigned int prog_data[%u] =\n",len);
    fprintf(fp,"{\n");
    for(ra=0;ra<len;ra++)
    {
        fprintf(fp,"0x%08X,//0x%08X\n",data[ra],ra<<2);
    }
    fprintf(fp,"};\n");
    fprintf(fp,"\n");
    fclose(fp);

    return(0);
}


