#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc!=3){
        printf("Usage: ./combine_nums num1 num2\n");
        return -1;
    }
    int a=0, b=0, c=0;
    printf("argv[1]=%s argv[2]=%s\n", argv[1], argv[2]);
    a=(int)strtol(argv[1], NULL, 0);
    b=(int)strtol(argv[2], NULL, 0);
    c=(b&0xFFFFFF00)|(a&0xFF);
    //c=b&0xFFFFFF00;
    printf("a=0x%x b=0x%x result=0x%x\n", a, b, c);

    return 0;
}