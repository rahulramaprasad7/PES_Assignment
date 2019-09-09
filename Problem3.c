#include <stdio.h>

int main()
{
    int Input = 0xCAFE;
    printf("%x\n",Input);
    int temp=0;

    if(Input & 7 == 7)
        printf("True\t%d\n",(Input & 7));
    else
        printf("False\t%d\n",(Input & 7));

    temp = Input & 0xFF;
    Input = Input >> 8;
    Input = Input | (temp << 8);
    printf("%x\n",Input);

    if(Input & 7 == 7)
        printf("True\t%d\n",(Input & 7));
    else
        printf("False\t%d\n",(Input & 7));

    temp = Input & 0x0F;
    Input = Input >> 4;
    Input = Input | (temp << 12);
    printf("%x\n",Input);

    if(Input & 7 == 7)
        printf("True\t%d\n",(Input & 7));
    else
        printf("False\t%d\n",(Input & 7));

    temp = Input & 0xFF;
    Input = Input >> 8;
    Input = Input | (temp << 8);
    printf("%x\n",Input);
    
    if(Input & 7 == 7)
        printf("True\t%d\n",(Input & 7));
    else
        printf("False\t%d\n",(Input & 7));
}