#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct a {
	int32_t value;
	int32_t radix;
	int32_t opSize;
} datastructure[11];

bool negative = false;
int32_t operand = 0, min = 0, max = 0;
int32_t value, radix, opSize, compMins;

void convToBin(int32_t input, int32_t opSize);
int32_t onesComp(int32_t signedNo, int32_t opSize);
int32_t twosComp(int32_t signedNo, int32_t opSize);
int32_t toSigned(int32_t unsignedNo, int32_t opSize);
void printAbsBin(void);
void printAbsOct(void);
void printAbsDec(void);
void printAbsHex(void);
void printSignedBin(void);
void printSignOnesComp(void);
void printSignTwosComp(void);
void printAllOutputs(void);



int main()
{
	char *ptr;
	char input[] = "{-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {0xEB, 10, 4}, {237, 10, 8}, {0354, 8, 8}, {78, 16, 8}, {-125, 10, 8},  {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16} ";
	ptr = input;

	int32_t inputQuantity = 0;
	for ( int32_t i = 0; i < strlen(input); ++i)
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

	// printf("%d\n", inputQuantity);
	// for ( int32_t i = 0; i < 11; i++ )
	// 	printf("%d %d %d ", datastructure[i].value, datastructure[i].radix, datastructure[i].opSize);

	printf("\n");

	for (int32_t i = 0; i < inputQuantity; ++i)
	{
		negative = false;
		operand = 0;
		min = 0;
		max = 0;
		compMins = 0;

		value = datastructure[i].value;
		radix = datastructure[i].radix;
		opSize = datastructure[i].opSize;
		printAllOutputs();

		printf("\n");
	}


	return 0;

}

void printAllOutputs(void)
{
	if (value < 0) {
		negative = true;
		operand = -1 * value;
	} else {
		operand = value;
	}

	//max & min unsigned
	for (int32_t i = opSize - 1; i >= 0; i--)
	{
		max += (1 << i);
	}
	min = 0;

	//print Ouptut header
	printf("Input:  Value %d \t Radix %d \t Operand Size %d\n", value, radix, opSize);
	if(opSize == 4)
		printf("Output: \t\tValue \t\tMaximum \tMinimum\n");
	else if(opSize == 8)
		printf("Output: \t\tValue \t\t\tMaximum \t\tMinimum\n");
	else if(opSize == 16)
		printf("Output: \t\tValue \t\t\t\tMaximum \t\t\tMinimum\n");

	printAbsBin();
	printAbsOct();
	printAbsDec();
	printAbsHex();


	//converting to signed number
	operand = toSigned(operand, opSize);

	//signed max and mins
	max = 0;
	for (int32_t i = opSize - 2; i >= 0; i--)
	{
		max += (1 << i);
	}
	min = 0;
	for (int32_t i = opSize - 1; i >= 0; i--)
	{
		min += (1 << i);
	}

	//min values for ones and twos complement
	compMins = 1 << (opSize - 1);

	printSignOnesComp();
	printSignTwosComp();
	printSignedBin();
}

void printAbsBin(void)
{
	/* BIN */
	printf("Binary (abs) \t\t");
	convToBin(operand, opSize);
	convToBin(max, opSize);
	convToBin(min, opSize);

	printf("\n");
}

void printAbsOct(void)
{
	/* OCTAL */
	printf("Octal (abs) \t\t");
	printf("0%o\t\t", operand);
	if(opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0%o\t\t", max);
	if(opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0%o\t", min);

	printf("\n");
}

void printAbsDec(void)
{
	/* DECIMAL */
	printf("Decimal (abs) \t\t");
	printf("%d\t\t", operand);
	if(opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("%d\t\t", max);
	if(opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("%d\t", min);

	printf("\n");
}

void printAbsHex(void)
{
	/* HEX */
	printf("Hexadecimal (abs) \t");
	printf("0x%x\t\t", operand);
	if(opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0x%x\t\t", max);
	if(opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0x%x\t", min);

	printf("\n");
}

void printSignOnesComp(void)
{
	/* ONES COMPLEMENT */
	printf("Signed One's Compliment\t");
	convToBin(onesComp(operand, opSize), opSize);
	convToBin(max, opSize);
	convToBin(compMins, opSize);

	printf("\n");
}

void printSignTwosComp(void)
{
	/* TWOS COMPLEMENT */
	printf("Signed Two's Compliment\t");
	convToBin(twosComp(operand, opSize), opSize);
	convToBin(max, opSize);
	convToBin(compMins, opSize);

	printf("\n");
}

void printSignedBin(void)
{
	/* SIGNED OPERAND */
	printf("Signed Magnitude \t");
	convToBin(operand, opSize);
	convToBin(max, opSize);
	convToBin(min, opSize);

	printf("\n");
}

void convToBin(int32_t input, int32_t opSize)
{
	printf("0b");
	for (int32_t i = opSize - 1; i >= 0; i--)
	{
		printf("%d", (input >> i) & 0x01);
	}
	printf("\t\t");
}

int32_t onesComp(int32_t signedNoInput, int32_t opSize)
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

int32_t twosComp(int32_t signedNoInput, int32_t opSize)
{
	return (onesComp(signedNoInput, opSize) + 1);
}

int32_t toSigned(int32_t unsignedNoInput, int32_t opSize)
{
	if (negative) {
		unsignedNoInput += (1 << (opSize - 1));
	} else {
		unsignedNoInput &= ~(1 << (opSize - 1));
	}
	return unsignedNoInput;
}
