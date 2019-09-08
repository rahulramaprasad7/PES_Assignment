#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    struct a{
        int value;
        int base;
        int radix;
    }datastructure[11];
    char *ptr;
    char test[]="{-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {-9, 10, 4}, {237, 10, 8}, {0354, 8, 8}, {78, 16, 8}, {-125, 10, 8},  {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16} ";
    ptr=test;
    int j=0;
    for ( int i=0; i<strlen(test); ++i)
    {
        if (test[i]=='{')
        {
            sscanf(ptr+i,"{%d,%d,%d}",&datastructure[j].value,&datastructure[j].base,&datastructure[j].radix);
            j++;
        }
    }
    printf("%d\n",j);
    for ( int i=0; i<11; i++ )
      printf("%d %d %d ", datastructure[i].value,datastructure[i].base,datastructure[i].radix);
    return 0;
}
