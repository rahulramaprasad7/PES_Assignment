#include <stdio.h>
#include <stdint.h>


void printBin(int32_t input)
{
    int32_t i;
    printf("The binary value is\n");
    printf("0b");
    for (i = 15; i >= 0; i--)
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
    if ((input & 0x07) == 0x07) {
        printf("True\n");
        printBin(input);
    }
    else {
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    //Reverse the byte order, print the value in hexadecimal
    printf("Reversing the byte order & printing the value in hexadecimal\n");
    temp = input & 0xFF;
    input = input >> 8;
    input = input | (temp << 8);
    printf("0x%X\n", input);
    printf("\n");

    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Testing if 3 of last 4 bits are on, and printing the value in binary\n");
    if ((input & 7) == 7) {
        printf("True\n");
        printBin(input);
    }
    else {
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    //Rotate the value by four bits to the left, print the value in hexadecimal
    printf("Rotating the value by four bits to the left and printing the value in hexadecimal\n");
    temp = input & 0x0F;
    input = input >> 4;
    input = input | (temp << 12);
    printf("0x%X\n", input);
    printf("\n");

    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Testing if 3 of last 4 bits are on, and printing the value in binary\n");
    if ((input & 7) == 7) {
        printf("True\n");
        printBin(input);
    }
    else {
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    //Rotate the value by eight bits to the right, print the value in hexadecimal
    printf("Rotating the value by eight bits to the right, printing the value in hexadecimal\n");
    temp = input & 0xFF;
    input = input >> 8;
    input = input | (temp << 8);
    printf("0x%X\n", input);
    printf("\n");

    //Test if 3 of last 4 bits are on, and print the value in binary
    printf("Testing if 3 of last 4 bits are on, and printing the value in binary\n");
    if ((input & 7) == 7) {
        printf("True\n");
        printBin(input);
    }
    else {
        printf("False\n");
        printBin(input);
    }
    printf("\n");

    return 0;
}
