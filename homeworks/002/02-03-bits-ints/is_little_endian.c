#include <stdio.h>

int main(int argc, char** argv)
{
    short a=0x1234;

    char* addr=&a;
    if(addr[0]==0x12&&addr[1]==0x34)printf("0\n");
    else if(addr[0]==0x34&&addr[1]==0x12)printf("1\n");

    return -1;
}