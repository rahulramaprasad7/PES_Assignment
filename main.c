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
int onesComp(int signedNo, bool neg, int opSize);
int twosComp(int signedNo, bool neg, int opSize);
int toSigned(int unsignedNo, int opSize);

// Here is a quick summary of how to find the 1's complement representation of any decimal number x.
// If x is positive, simply convert x to binary.
// If x is negative, write the positive value of x in binary
// Reverse each bit.

// Here is a quick summary of how to find the 2's complement representation of any decimal number x. Notice the first three steps are the same as 1's complement.
// If x is positive, simply convert x to binary.
// If x is negative, write the positive value of x in binary
// Reverse each bit.
// Add 1 to the complemented number.


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

			if ((datastructure[inputQuantity].value == 0 && datastructure[inputQuantity].radix == 0 && datastructure[inputQuantity].opSize == 0))
				sscanf(ptr + i, "{%x,%d,%d}", &datastructure[inputQuantity].value, &datastructure[inputQuantity].radix, &datastructure[inputQuantity].opSize);

			if (datastructure[inputQuantity].radix == 8)
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

	if (value < 0) {
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
	min = 0;
	printBIN(max, opSize);
	printBIN(min, opSize);

	printf("\n");

	/* OCTAL */
	printf("0%o\t", operand);
	printf("0%o\t", max);
	printf("0%o\t", min);

	printf("\n");

	/* DECIMAL */
	printf("%d\t", operand);
	printf("%d\t", max);
	printf("%d\t", min);

	printf("\n");

	/* HEX */
	printf("0x%x\t", operand);
	printf("0x%x\t", max);
	printf("0x%x\t", min);

	printf("\n");

	//converting to signed number
	operand = toSigned(operand, opSize);

	max = 0;
	for (int i = opSize - 2; i >= 0; i--)
	{
		max += (1 << i);
	}
	min = 0;
	for (int i = opSize - 1; i >= 0; i--)
	{
		min += (1 << i);
	}

	int compMins = 1 << (opSize - 1);

	printBIN(onesComp(operand, negative, opSize), opSize);
	printBIN(max, opSize);
	printBIN(compMins, opSize);

	printf("\n");

	/* TWOS COMPLEMENT */
	printBIN(twosComp(operand, negative, opSize), opSize);
	printBIN(max, opSize);
	printBIN(compMins, opSize);

	printf("\n");

	/* SIGNED OPERAND */
	printBIN(operand, opSize);
	printBIN(max, opSize);
	printBIN(min, opSize);

	printf("\n");

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

int onesComp(int signedNoInput, bool neg, int opSize)
{
	//If negative
	if (signedNoInput & (1 << (opSize - 1)))
	{
		signedNoInput &= ~(1 << (opSize - 1));
		signedNoInput = ~signedNoInput;
		return signedNoInput;
	} else {
		return ((signedNoInput & (1 << (opSize - 1))) + ~(signedNoInput));
	}
}

int twosComp(int signedNoInput, bool neg, int opSize)
{
	return (onesComp(signedNoInput, neg, opSize) + 1);
}

int toSigned(int unsignedNoInput, int opSize)
{
	if (negative) {
		unsignedNoInput += (1 << (opSize - 1));
	} else {
		unsignedNoInput &= ~(1 << (opSize - 1));
	}

	printf("\n%x\n", unsignedNoInput);

	return unsignedNoInput;
}
