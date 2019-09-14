/*
 * @file Problem1.c
 * @brief Soultion for the first problem of the PES project
 *
 * This is a C program takes as input astring comtaining multiple sets of
 * numeric values, radix, and operand sizes, and outputs a table containing
 * the following values:
 * Binary (abs)
 * Octal (abs)
 * Decimal (abs)
 * Hexadecimal (abs)
 * Signed One’s Compliment
 * Signed Two’s Compliment
 * Sign-Magnitude
 *
 * @author Rahul Ramaprasad, Prayag Milan Desai
 * @date September 14 2019
 * @version 1.0
 */


#include "Problem1.h"



int32_t main()
{

	//Pointer to the location of the input string
	char *stringLocationPtr = NULL;

	//The input string, it's format being {value, Radix, Operand Size}
	char input[] = "{-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {0xEB, 10, 4},\
	                {237, 10, 8}, {0354, 8, 8}, {78, 16, 8}, {-125, 10, 8},\
	                {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16} ";
	stringLocationPtr = input;

	//Total number of inputs extracted from the input string
	int32_t inputQuantity = 0;

	//This for loop extracts the value, radix and operand size from the input
	//string and saves them in their corresponding structure
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

	//This loop performs the required operations on all the inputs and outputs
	//a table with the results
	for (int32_t i = 0; i < inputQuantity; ++i)
	{
		//Reset all variables for a new input
		negative = false;						//If the input is negative
		operand = 0;							//Value of operand
		min = 0;								//Minimim val of operand
		max = 0;								//Maximum val of oprand
		compMins = 0;							//Min value of 1's and 2's comp
		error = false;
		value = numProperties[i].value;
		radix = numProperties[i].radix;
		opSize = numProperties[i].opSize;

		//Check if radix is out of bounds
		if ((radix != 8) && (radix != 10) && (radix != 16))
		{
			printf("Error: The Radix value is not acceptable for the input "
			       "{%d %d %d}\n", value, radix, opSize);
			printf("The radix should be 8, 10 or 16, and the input radix is "
			       "%d\n", radix);
			error = true;						//Set error if out of bounds
			printf("\n");
		}

		//Check if operand size is out of bounds
		if ((opSize != 4) && (opSize != 8) && (opSize != 16))
		{
			printf("Error: The Operand Size is not acceptable for the input"
			       " {%d %d %d}\n", value, radix, opSize);
			printf("The operand size should be 4, 8 or 16, and the input"
			       "operand size is %d\n", opSize);
			error = true;						//Set error if out of bounds
			printf("\n");
		}

		//Start calculating the output if the input is free from operand size
		//and radix errors
		if (!error)
			printAllOutputs();

		printf("\n");
	}


	return 0;

}

void printAllOutputs(void)
{
	//reset the error bool
	error = false;

	//Check if the value is negative, and convert it to positive for
	//absolute value calculations
	if (value < 0) {
		negative = true;
		operand = -1 * value;
	} else {
		operand = value;
	}

	//Maximum and minimum values of the absolute input
	for (int32_t i = opSize - 1; i >= 0; i--)
	{
		max += (1 << i);
	}
	min = 0;
	
	//Print Ouptut header
	printf("Input:  Value %d \t Radix %d \t Operand Size %d\n",
	       value, radix, opSize);

	//The maximum value of an unsigned integer of opSize bytes
	int32_t maxUnsignedVal = pow(2, opSize);

	//Print absolute values if the input is less than the maximum 
	//value of an unsigned integer i.e input is valid
	if ( value <=  maxUnsignedVal)
	{
		if (opSize == 4)
			printf("Output: \t\tValue \t\tMaximum \tMinimum\n");
		else if (opSize == 8)
			printf("Output: \t\tValue \t\t\tMaximum \t\tMinimum\n");
		else if (opSize == 16)
			printf("Output: \t\tValue \t\t\t\tMaximum \t\t\tMinimum\n");

		//Print values in different radix
		printAbsBin();
		printAbsOct();
		printAbsDec();
		printAbsHex();

		//Convert input to signed number
		operand = toSigned(operand, opSize);

		//Generate max and min values of a signed number
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

		//Generate minimum values for a 1's and 2's complement number
		compMins = 1 << (opSize - 1);

		int32_t maxOpValue = (pow(2, opSize) / 2) - 1;
		int32_t minOpValue = (pow(2, opSize) / 2) * -1;

		//If the input is greater or less than the signed range for the given
		//operand size, give error
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
			//Print signed outputs
			printSignOnesComp();
			printSignTwosComp();
			printSignedBin();

		}
	}
	//If the input is greater than the unsigned range for the given operand
	//size, give error
	else
	{
		printf("Error: The input value is greater than the range for the given "
		       "operand size of the input {%d %d %d}\n", value, radix, opSize);
		printf("The given value is %d and the maximum unsigned value for the  "
		       "given operand is %d\n", value, maxUnsignedVal);
		error = true;
		printf("\n");
	}
}

//print binary results
void printAbsBin(void)
{
	printf("Binary (abs) \t\t");
	convToBin(operand, opSize);
	convToBin(max, opSize);
	convToBin(min, opSize);

	printf("\n");
}

//print octal results
void printAbsOct(void)
{
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

//print decimal results
void printAbsDec(void)
{
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

//print hex results
void printAbsHex(void)
{
	printf("Hexadecimal (abs) \t");
	printf("0x%X\t\t", operand);
	if (opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0x%X\t\t", max);
	if (opSize == 8)
		printf("\t");
	else if (opSize == 16)
		printf("\t\t");
	printf("0x%X\t", min);

	printf("\n");
}

//print 1's complement results
void printSignOnesComp(void)
{
	printf("Signed One's Compliment\t");
	convToBin(onesComp(operand, opSize), opSize);
	convToBin(max, opSize);
	convToBin(compMins, opSize);

	printf("\n");
}

//print 2's complement results
void printSignTwosComp(void)
{
	printf("Signed Two's Compliment\t");
	convToBin(twosComp(operand, opSize), opSize);
	convToBin(max, opSize);
	convToBin(compMins, opSize);

	printf("\n");
}

//print signed magnitude results
void printSignedBin(void)
{
	printf("Signed Magnitude \t");
	convToBin(operand, opSize);
	convToBin(max, opSize);
	convToBin(min, opSize);

	printf("\n");
}

//Convert a given number to binary
void convToBin(int32_t input, int32_t opSize)
{
	printf("0b");
	for (int32_t i = opSize - 1; i >= 0; i--)
	{
		printf("%d", (input >> i) & 0x01);
	}
	printf("\t\t");
}

//Find 1's complement of a number
int32_t onesComp(int32_t signedNoInput, int32_t opSize)
{
	//If negative, negate all bits except the sign bit
	//If positive, return the same number
	if (signedNoInput & (1 << (opSize - 1)))
	{
		signedNoInput &= ~(1 << (opSize - 1));
		signedNoInput = ~signedNoInput;
		return signedNoInput;
	} else {
		return signedNoInput;
	}
}

//Find 2's complement of a number
int32_t twosComp(int32_t signedNoInput, int32_t opSize)
{
	//If negative, return the value of 1's complement + 1
	//If positive, return the same number
	if (negative)
		return (onesComp(signedNoInput, opSize) + 1);
	else
		return signedNoInput;
}

//Convert the value to a signed number
int32_t toSigned(int32_t unsignedNoInput, int32_t opSize)
{
	if (negative) {
		unsignedNoInput += (1 << (opSize - 1));
	} else {
		unsignedNoInput &= ~(1 << (opSize - 1));
	}
	return unsignedNoInput;
}
