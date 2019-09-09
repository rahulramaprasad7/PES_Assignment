#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    int x=0xCAFE;
    int z=x;
    int z1=x;
    printf("%x\n",x);
    if(x&4 && x&2 && x&1)
        printf("True    %d\n",(x&7));
    else
        printf("False    %d\n",(x&7));
    int y = z & 255;
    z= z >> 8;
    z = z | (y<<8);
    printf("%x\n",z);
    if(z&4 && z&2 && z&1)
        printf("True    %d\n",(z&7));
    else
        printf("False    %d\n",(z&7));
    y = z1 & 15;
    z1= z1 >> 4;
    z1 = z1 | (y<<12);
    printf("%x",z1);
	int z2=z1;
    if(z1&4 && z1&2 && z1&1)
        printf("True    %d\n",(z1&7));
    else
        printf("False    %d\n",(z1&7));
    y = z2 & 255;
    z2= z2 >> 8;
    z2 = z2 | (y<<8);
	printf("%x\n",z2);
	if(z2&4 && z2&2 && z2&1)
        printf("True    %d\n",(z2&7));
    else
        printf("False    %d\n",(z2&7));
}