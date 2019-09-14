#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h> 
int32_t main()
{
	char input[] = {66,114,117,99,101,32,83,97,121,30,115,32,72,105,33,7,9,50, \
					48,49,57,30};
	char lookUpTableSpecial[] = {33,34,35,36,37,38,39,40,41,42,43,44,45,46,47, \
								 58,59,60,61,62,63,64,91,92,93,94,95,96,123, \
								 124,15,126}; //http://www.asciitable.com/ for checking ASCII range
	int32_t i,j;
	bool check = true;
	for( i = 0; i < (sizeof(input)/sizeof(char)); i++)
	{
		if( isupper( input[i] ) )  //To check if the input Character is Upper Case Alphabet
			printf("Code: %d 	Type:Upper Case 	"
				   "ASCII Char: %c\n",input[i],input[i]);
		
		else if( islower( input[i] ) )  //To check if the input Character is Lower Case Alphabet
			printf("Code: %d 	Type:Lower Case		"
				   "ASCII Char: %c\n",input[i],input[i]);
			
		else if( isdigit( input[i] ) )  //To check if the input Character is Digit
			printf("Code: %d 	Type:Digit		"
				   "ASCII Char: %c\n",input[i],input[i]);
		
		else if( isspace(input[i]) || (input[i] == 8) )  //To check if the input Character is a Space and 8 is ASCII code for backspace
			printf("Code: %d 	Type:Space		"
				   "ASCII Char: %c\n",input[i],input[i]);
		
		else if( check )  //To check if the input character is special 
		{	
			for ( j = 0; j < (sizeof(lookUpTableSpecial)/sizeof(char)); j++) 
			{	
				if( input[i] == lookUpTableSpecial[j])
				{
					printf("Code: %d 	Type:Special		"
						   "ASCII Char: %c\n",input[i],input[i]);
					check = true;
					break;
				}
				check = false;  //If the input character is not special, keep the check false to execute else 
			}
		}
		
		else 	  //To check if the input character does not fall under any of the categories above
			printf("The ASCII code %d does not fall under any "
				   "category\n",input[i]);
		
	}
	return 0;
}
