#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct a {
	int value;
	int radix;
	int opSize;
} datastructure[11];

bool negative = false;
int operand = 0, min = 0, max = 0;

void printBIN(int input, int opSize);

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

	printf("\n");

	int value = datastructure[0].value;
	int radix = datastructure[0].radix;
	int opSize = datastructure[0].opSize;

	if(value < 0){
		negative = true;
		operand = -1 * value;
	} else {
		operand = value;
	}

	/* BIN */
	printBIN(operand, opSize);
	//max
	for (int i = opSize - 1; i >= 0; i--)
	{
		max += (1 << i);
	}
	printBIN(max, opSize);
	printBIN(0, opSize);

	printf("\n");

	/* OCTAL */
	printf("0%o\t", operand);
	printf("0%o\t", max);
	printf("0%o\t", 0);

	printf("\n");

    /* DECIMAL */
	printf("%d\t", operand);
	printf("%d\t", max);
	printf("%d\t", 0);

	printf("\n");

	/* HEX */
	printf("0x%x\t", operand);
	printf("0x%x\t", max);
	printf("0x%x\t", 0);

	printf("\n");

    //converting to signed number
	if(negative){
		operand += 1 << (opSize - 1);
	}

	printBIN(operand, opSize);

	return 0;
}

void printBIN(int input, int opSize)
{
	printf("0b");
	for (int i = opSize - 1; i >= 0; i--)
	{
		printf("%d", (input >> i) & 0x01);
	}
	printf("\t");	
}