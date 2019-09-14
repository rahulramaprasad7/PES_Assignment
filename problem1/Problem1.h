/*
 * @file Problem1.h
 * @brief Header file containing the function declarations and global
 * variables for the file Problem1.c
 *
 * This is a Header file containing the function declarations and global
 * variables for the file Problem1.c, and provides a discription of the 
 * functions used in the same
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date September 14 2019
 * @verison 1.0
 */


#ifndef _Problem1_h
#define _Problem1_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

//This structure saves the value, radix (base) and the operand size of all the
//inputs. Increase the number of numProperties for more inputs
struct dataStructure
{
	int32_t value;		//Value of the operand
	int32_t radix;		//Base or radix of the operand
	int32_t opSize;		//Size of the operand
} numProperties[11];

//Boolean indicates if the input value is negative
bool negative = false;

//Boolean indicates if there are any oprand size, radix or value greater
//than limits of operand size errors
bool error = false;

//These integers save the operand, and the max and min values of the same
int32_t operand = 0, min = 0, max = 0;

//These integers save the number properties again, to perform operations on
//them, and saves the minimum value of 1's and 2's complement
int32_t value, radix, opSize, compMins;


/*
 * @brief Print the binary value for a given integer
 *
 * Given an integer input and an operand size, this function will print a 
 * binary value of the same
 *
 * @param input The input integer
 * @param opSize The operand size of the input integer
 *
 * @return void.
 */
void convToBin(int32_t input, int32_t opSize);


/*
 * @brief Find the ones complement of a signed number
 *
 * Given an integer input and an operand size, this function will find and
 * return the 1's complement of a signed number
 *
 * @param signedNo An input signed number
 * @param opSize The operand size of the signed number
 *
 * @return One's complement of the input signed number
 */
int32_t onesComp(int32_t signedNo, int32_t opSize);


/*
 * @brief Find the twos complement of a signed number
 *
 * Given an integer input and an operand size, this function will find and
 * return the 2's complement of a signed number
 *
 * @param signedNo An input signed number
 * @param opSize The operand size of the signed number
 *
 * @return Twos's complement of the input signed number
 */
int32_t twosComp(int32_t signedNo, int32_t opSize);


/*
 * @brief Covert an input unsigned number to a signed number
 *
 * Given an  integer input and an operand size, this function will check if the
 * number is negative using the 'negative' boolean, and add a signed bit to
 * the number based on the operand size
 *
 * @param unsignedNo An input unsigned number
 * @param opSize The operand size of the signed number
 *
 * @return Signed value for an input unsigned number
 */
int32_t toSigned(int32_t unsignedNo, int32_t opSize);


/*
 * @brief Print the absolute octal values for the operand, and its max and 
 * min values
 *
 * For the given absoulte value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and min 
 * integers, this function prints the aforementioned values in binary
 *
 * @param void
 *
 * @return void
 */
void printAbsBin(void);


/*
 * @brief Print the absolute octal values for the operand, and its max and 
 * min values
 *
 * For the given absoulte value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and min 
 * integers, this function prints the aforementioned values in octal
 *
 * @param void
 *
 * @return void
 */
void printAbsOct(void);


/*
 * @brief Print the absolute deciaml values for the operand, and its max and 
 * min values, given the oprand size
 *
 * For the given absoulte value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and min 
 * integers, this function prints the aforementioned values in decimal
 *
 * @param void
 *
 * @return void
 */
void printAbsDec(void);


/*
 * @brief Print the absolute hexadecimal values for the operand, and its max and 
 * min values, given the oprand size
 *
 * For the given absoulte value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and min 
 * integers, this function prints the aforementioned values in hexadecimal
 *
 * @param void
 *
 * @return void
 */
void printAbsHex(void);


/*
 * @brief Print the signed binary values for the operand, and its max and 
 * min values
 *
 * For the given signed value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and min 
 * integers, this function prints the aforementioned values in binary
 *
 * @param void
 *
 * @return void
 */
void printSignedBin(void);


/*
 * @brief Print the signed ones complement binary values for the operand,
 * and its max and min values
 *
 * For the given signed value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and compMins 
 * integers, this function prints the aforementioned values in binary
 *
 * @param void
 *
 * @return void
 */
void printSignOnesComp(void);


/*
 * @brief Print the signed twos complement binary values for the operand,
 * and its max and min values
 *
 * For the given signed value saved in the operand integer, and the maximum
 * and minimum values for the given operand sizes saved in the max and compMins 
 * integers, this function prints the aforementioned values in binary
 *
 * @param void
 *
 * @return void
 */
void printSignTwosComp(void);


/*
 * @brief Prints the above fuctions, after checking for overflow errors
 *
 * Compares the operand with the maximum value for a given operand size, and
 * prints the output table using the functions listed above, providing that
 * no errors are detected
 *
 * @param void
 *
 * @return void
 */
void printAllOutputs(void);

#endif 					//_Problem1_h
