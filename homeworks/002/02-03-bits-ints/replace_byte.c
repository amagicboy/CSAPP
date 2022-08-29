#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc!=4)
    {
        printf("Usage: ./replace_byte num pos replace_num\n");
        return -1;
    }
    int num=0, pos=0, replace_num=0;
    num=(int)strtol(argv[1], NULL, 0);
    pos=(int)strtol(argv[2], NULL, 0);
    replace_num=(int)strtol(argv[3], NULL, 0);

    printf("before replace num=0x%x\n", num);
    num=num&(~(0xFF<<(pos*8)));
    num=num|(replace_num<<(pos*8));
    printf("after  replace num=0x%x\n", num);
    return 0;
}