#include "Problem1.h"


int32_t main()
{
	char *stringLocationPtr = NULL;
	char input[] = "{-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {0xEB, 10, 4},\
	                {237, 10, 8}, {0354, 8, 8}, {78, 16, 8}, {-125, 10, 8},\
	                {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16} ";
	stringLocationPtr = input;
	bool error = false;
	int32_t inputQuantity = 0;
	for ( int32_t i = 0; i < strlen(input); ++i)
	{
		if (input[i] == '{')
		{
			sscanf(stringLocationPtr + i, "{%d,%d,%d}",\
				   &numProperties[inputQuantity].value, \
				   &numProperties[inputQuantity].radix, \
			       &numProperties[inputQuantity].opSize); \

			if ((numProperties[inputQuantity].value == 0 && \
			        numProperties[inputQuantity].radix == 0 && \
			        numProperties[inputQuantity].opSize == 0))\
				sscanf(stringLocationPtr + i, "{%x,%d,%d}", \
				       &numProperties[inputQuantity].value, \
				       &numProperties[inputQuantity].radix, \
				       &numProperties[inputQuantity].opSize);

			if (numProperties[inputQuantity].radix == 8)
				sscanf(stringLocationPtr + i, "{%o,%d,%d}", \
				       &numProperties[inputQuantity].value, \
				       &numProperties[inputQuantity].radix, \
				       &numProperties[inputQuantity].opSize);

			inputQuantity++;
		}
	}

	printf("\n");

	for (int32_t i = 0; i < inputQuantity; ++i)
	{
		negative = false;
		operand = 0;
		min = 0;
		max = 0;
		compMins = 0;
		error = false;
		value = numProperties[i].value;
		radix = numProperties[i].radix;
		opSize = numProperties[i].opSize;

		if ((radix != 8) && (radix != 10) && (radix != 16))
		{
			printf("Error: The Radix value is not acceptable for the input "
			       "{%d %d %d}\n", value, radix, opSize);
			printf("The radix should be 8, 10 or 16, and the input radix is "
			       "%d\n", radix);
			error = true;
			printf("\n");
		}

		if ((opSize != 4) && (opSize != 8) && (opSize != 16))
		{
			printf("Error: The Operand Size is not acceptable for the input"
			       " {%d %d %d}\n", value, radix, opSize);
			printf("The operand size should be 4, 8 or 16, and the input"
			       "operand size is %d\n", opSize);
			error = true;
			printf("\n");
		}

		if (!error)
			printAllOutputs();

		printf("\n");
	}


	return 0;

}

void printAllOutputs(void)
{
	bool error = false;

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
	printf("Input:  Value %d \t Radix %d \t Operand Size %d\n",
	       value, radix, opSize);

	int32_t maxUnsignedVal = pow(2, opSize);

	if ( value <=  maxUnsignedVal)
	{
		if (opSize == 4)
			printf("Output: \t\tValue \t\tMaximum \tMinimum\n");
		else if (opSize == 8)
			printf("Output: \t\tValue \t\t\tMaximum \t\tMinimum\n");
		else if (opSize == 16)
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

		int32_t maxOpValue = (pow(2, opSize) / 2) - 1;
		int32_t minOpValue = (pow(2, opSize) / 2) * -1;

		if (value > maxOpValue)
		{
			printf("Error: The input value is greater than the range for the "
			       "given operand size of the input {%d %d %d}\n", \
			       value, radix, opSize);
			printf("The given value is %d and the maximum value for the given "
			       "signed operand is %d\n", value, maxOpValue);
			error = true;
			printf("\n");
		}

		else if (value < minOpValue)
		{
			printf("Error: The input value is less than the range for the "
			       "given operand size of the input {%d %d %d}\n", \
			       value, radix, opSize);
			printf("The given value is %d and the minimum value for the "
			       "given signed operand is %d\n", value, minOpValue);
			error = true;
			printf("\n");
		}

		else
		{

			printSignOnesComp();
			printSignTwosComp();
			printSignedBin();

		}
	}
	else
	{
		printf("Error: The input value is greater than the range for the given "
		       "operand size of the input {%d %d %d}\n", value, radix, opSize);
		printf("The given value is %d and the maximum value for the given "
		       "operand is %d\n", value, maxUnsignedVal);
		error = true;
		printf("\n");
	}
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
	if (opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0%o\t\t", max);
	if (opSize == 8)
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
	if (opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("%d\t\t", max);
	if (opSize == 8)
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
	if (opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0x%x\t\t", max);
	if (opSize == 8)
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
