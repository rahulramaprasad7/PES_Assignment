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
int value, radix, opSize, compMins;

void convToBin(int input, int opSize);
int onesComp(int signedNo, int opSize);
int twosComp(int signedNo, int opSize);
int toSigned(int unsignedNo, int opSize);
void printAbsBin(void);
void printAbsOct(void);
void printAbsDec(void);
void printAbsHex(void);
void printSignedBin(void);
void printSignOnesComp(void);
void printSignTwosComp(void);


int main()
{
	char *ptr;
	char input[] = "{-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {0xEB, 10, 4}, {237, 10, 8}, {0354, 8, 8}, {78, 16, 8}, {-125, 10, 8},  {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16} ";
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

	value = datastructure[0].value;
	radix = datastructure[0].radix;
	opSize = datastructure[0].opSize;

	if (value < 0) {
		negative = true;
		operand = -1 * value;
	} else {
		operand = value;
	}

	//max & min unsigned
	for (int i = opSize - 1; i >= 0; i--)
	{
		max += (1 << i);
	}
	min = 0;


	printAbsBin();
	printAbsOct();
	printAbsDec();
	printAbsHex();


	//converting to signed number
	operand = toSigned(operand, opSize);

	//signed max and mins
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

	//min values for ones and twos complement
	compMins = 1 << (opSize - 1);

	printSignOnesComp();
	printSignTwosComp();
	printSignedBin();

	return 0;
}

void printAbsBin(void)
{
	/* BIN */
	convToBin(operand, opSize);
	convToBin(max, opSize);
	convToBin(min, opSize);

	printf("\n");
}

void printAbsOct(void)
{
	/* OCTAL */
	printf("0%o\t", operand);
	printf("0%o\t", max);
	printf("0%o\t", min);

	printf("\n");
}

void printAbsDec(void)
{
	/* DECIMAL */
	printf("%d\t", operand);
	printf("%d\t", max);
	printf("%d\t", min);

	printf("\n");
}

void printAbsHex(void)
{
	/* HEX */
	printf("0x%x\t", operand);
	printf("0x%x\t", max);
	printf("0x%x\t", min);

	printf("\n");
}

void printSignOnesComp(void)
{
	/* ONES COMPLEMENT */
	convToBin(onesComp(operand, opSize), opSize);
	convToBin(max, opSize);
	convToBin(compMins, opSize);

	printf("\n");
}

void printSignTwosComp(void)
{
	/* TWOS COMPLEMENT */
	convToBin(twosComp(operand, opSize), opSize);
	convToBin(max, opSize);
	convToBin(compMins, opSize);

	printf("\n");
}

void printSignedBin(void)
{
	/* SIGNED OPERAND */
	convToBin(operand, opSize);
	convToBin(max, opSize);
	convToBin(min, opSize);

	printf("\n");
}

void convToBin(int input, int opSize)
{
	printf("0b");
	for (int i = opSize - 1; i >= 0; i--)
	{
		printf("%d", (input >> i) & 0x01);
	}
	printf("\t");
}

int onesComp(int signedNoInput, int opSize)
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

int twosComp(int signedNoInput, int opSize)
{
	return (onesComp(signedNoInput, opSize) + 1);
}

int toSigned(int unsignedNoInput, int opSize)
{
	if (negative) {
		unsignedNoInput += (1 << (opSize - 1));
	} else {
		unsignedNoInput &= ~(1 << (opSize - 1));
	}
	return unsignedNoInput;
}
