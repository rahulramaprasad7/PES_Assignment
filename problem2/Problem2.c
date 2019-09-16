/*
 * @file Problem2.c
 * @brief Soultion for the second problem of the PES project
 *
 * This is a C program takes as input, an array conatining a set of ASCII codes
 * and the output of the program prints the equivalent ASCII character 
 * after segregating into the following classes:
 * Upper Case Alphabets
 * Lower Case Alphabets
 * Digits
 * Spaces
 * Special Characters
 * None of the above
 *
 * @author Rahul Ramaprasad, Prayag Milan Desai
 * @date September 14 2019
 * @version 1.0
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h> 

int32_t main()
{
	
	//The input array of ASCII codes
	char input[] = {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48, \
		        49,57};
	
	//The look-up table made to segregate special characters 
	//(http://www.asciitable.com/ for checking ASCII range)
	char lookUpTableSpecial[] = {33,34,35,36,37,38,39,40,41,42,43,44,45,46,47, \
				     58,59,60,61,62,63,64,91,92,93,94,95,96,123, \
				     124,15,126}; 
	
	//Boolean variable used to check if the code is special character or if 
	//it does not fall under any category
	bool check = true;
	
	for( int32_t i = 0; i < (sizeof(input)/sizeof(char)); i++)
	{

		//To check if the input Character is Upper Case Alphabet
		if( isupper( input[i] ) )  
			printf("Code: %d 	Type:Upper Case 	"
				   "ASCII Char: %c\n",input[i],input[i]);
		
		//To check if the input Character is Lower Case Alphabet
		else if( islower( input[i] ) )  
			printf("Code: %d 	Type:Lower Case		"
				   "ASCII Char: %c\n",input[i],input[i]);
			
		//To check if the input Character is Digit	
		else if( isdigit( input[i] ) )  
			printf("Code: %d 	Type:Digit		"
				   "ASCII Char: %c\n",input[i],input[i]);
		
		//To check if the input Character is a Space and 8 is the 
		//ASCII code for backspace
		else if( isspace(input[i]) || (input[i] == 8) )  
			printf("Code: %d 	Type:Space		"
				   "ASCII Char: %c\n",input[i],input[i]);
	
		else   
		{	
			//To check if the input character is special using the look-up table
			if( check )
			{
				for ( int32_t j = 0; \
					  j < (sizeof(lookUpTableSpecial)/sizeof(char)); j++) 
				{	
					if( input[i] == lookUpTableSpecial[j])
					{
						printf("Code: %d 	Type:Special		"
							   "ASCII Char: %c\n",input[i],input[i]);
						check = true;
						break;
					}

					//If the input character is not special,
					//keep the check false to execute else
					check = false;   
				}
			}
			
			//To check if the input character does not fall under any of
			//the categories above
			if( !check )
			{
				printf("The ASCII code %d does not fall under any "
			       "category\n",input[i]);
				check=true;
			}
			
		}
		

		
			
	
	}
	return 0;
}
