/*
 * @file Problem3.c
 * @brief Soultion for the third problem of the PES project
 *
 * This is a C program takes an integer input in hexadecimal format,
 * and performs a series of byte rotation operations and 
 * also checks if 3 of the last 4 bits are on and if true, 
 * prints the value in binary
 *
 * @author Rahul Ramaprasad, Prayag Milan Desai
 * @date September 14 2019
 * @version 1.0
 */
#include <stdio.h>
#include <stdint.h>


/*
 * @brief Print the binary value for a given integer
 *
 * Given an integer input, this function will print a 
 * binary value of the same
 *
 * @param input The input integer
 * 
 * @return void.
 */
void printBin(int32_t input)
{
   
    printf("The binary value is\n");
    printf("0b");
	
    for (int32_t i = 15; i >= 0; i--)
    {
        printf("%d", (input >> i) & 0x01);
    }
	
    printf("\n");
}


int32_t main()
{
    printf("\n");

    //Print original in hex
    printf("The original number in HEX\n");
    int32_t input = 0xCAFE;
    printf("0x%X\n", input);
    int32_t temp = 0;
    printf("\n");

    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Are 3 of the last 4 bits on?\n");
    
    //There are four possibilities where 3 of the last 4 bits are on
    if ( ((input & 0x0F) == 0x07) || ((input & 0x0F) == 0x0B) \
	     || ((input & 0x0F) == 0x0D) || ((input & 0x0F) == 0x0E))
	{
        printf("True\n");
        printBin(input);
    }
	
    else
	{
        printf("False\n");
        printBin(input);
    }
    printf("\n");

	
    //Reverse the byte order, print the value in hexadecimal
    printf("Reversing the byte order & printing the value in hexadecimal\n");
    //Storing the last 8 bits in a temporary variable
    temp = input & 0xFF;
    //Right shifting the first 8 bits to take the place of last 8 bits	
    input = input >> 8;
    //Left shifting the temp 8 bits to left and ORing with right-shifted 8 bits
    input = input | (temp << 8);
    printf("0x%X\n", input);
    printf("\n");

	
    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Testing if 3 of last 4 bits are on, and printing the "
           "value in binary\n");
	
    //There are four possibilities where 3 of the last 4 bits are on	   
    if ( ((input & 0x0F) == 0x07) || ((input & 0x0F) == 0x0B) \
	     || ((input & 0x0F) == 0x0D) || ((input & 0x0F) == 0x0E))
	{
        printf("True\n");
        printBin(input);
    }
	
    else
	{
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    //Rotate the value by four bits to the left, print the value in hexadecimal
    printf("Rotating the value by four bits to the left and printing the"
           " value in hexadecimal\n");
    temp = input & 0x0F;
    input = input >> 4;
    input = input | (temp << 12);
    printf("0x%X\n", input);
    printf("\n");

	
    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Testing if 3 of last 4 bits are on, and printing the "
           "value in binary\n");
	
    //There are four possibilities where 3 of the last 4 bits are on	   
    if ( ((input & 0x0F) == 0x07) || ((input & 0x0F) == 0x0B) \
	     || ((input & 0x0F) == 0x0D) || ((input & 0x0F) == 0x0E))
	{
        printf("True\n");
        printBin(input);
    }
	
    else
	{
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    
    //Rotate the value by eight bits to the right, print the value in hexadecimal
    printf("Rotating the value by eight bits to the right, printing the "
           "value in hexadecimal\n");
    temp = input & 0xFF;
    input = input >> 8;
    input = input | (temp << 8);
    printf("0x%X\n", input);
    printf("\n");

	
    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Testing if 3 of last 4 bits are on, and printing the "
           "value in binary\n");
    if ( ((input & 0x0F) == 0x07) || ((input & 0x0F) == 0x0B) \
	     || ((input & 0x0F) == 0x0D) || ((input & 0x0F) == 0x0E))
	{
        printf("True\n");
        printBin(input);
    }
	
    else
	{
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    return 0;
}
