#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a {
	int value;
	int radix;
	int opSize;
} datastructure[11];


int main()
{
	char *ptr;
	char input[] = "{-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {0xff, 10, 4}, {237, 10, 8}, {0354, 8, 8}, {78, 16, 8}, {-125, 10, 8},  {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16} ";
	ptr = input;

	int inputQuantity = 0;
	for ( int i = 0; i < strlen(input); ++i)
	{
		if (input[i] == '{')
		{
			sscanf(ptr + i, "{%d,%d,%d}", &datastructure[inputQuantity].value, &datastructure[inputQuantity].radix, &datastructure[inputQuantity].opSize);

			if((datastructure[inputQuantity].value == 0 && datastructure[inputQuantity].radix == 0 && datastructure[inputQuantity].opSize == 0))
				sscanf(ptr + i, "{%x,%d,%d}", &datastructure[inputQuantity].value, &datastructure[inputQuantity].radix, &datastructure[inputQuantity].opSize);

			if(datastructure[inputQuantity].radix == 8)
				sscanf(ptr + i, "{%o,%d,%d}", &datastructure[inputQuantity].value, &datastructure[inputQuantity].radix, &datastructure[inputQuantity].opSize);

			inputQuantity++;
		}
	}

	printf("%d\n", inputQuantity);
	for ( int i = 0; i < 11; i++ )
		printf("%d %d %d ", datastructure[i].value, datastructure[i].radix, datastructure[i].opSize);

	return 0;
}
