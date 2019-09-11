#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
int32_t main()
{
	char input[]={66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};
	
	for( uint32_t i = 0; i <(sizeof(input)/sizeof(char)); i++)
	{
		if( isupper( input[i] ) )                                           		//http://www.asciitable.com/ for checking ASCII range
			printf("Code: %d 	Type:Upper Case 	ASCII Char: %c\n",input[i],input[i]);
		
		else if( islower( input[i] ) )
			printf("Code: %d 	Type:Lower Case		ASCII Char: %c\n",input[i],input[i]);
			
		else if( isdigit( input[i] ) )
			printf("Code: %d 	Type:Digit		ASCII Char: %c\n",input[i],input[i]);
		
		else if( isspace( input[i] ) )
			printf("Code: %d 	Type:Space		ASCII Char: %c\n",input[i],input[i]);
		
		else 
			printf("Code: %d 	Type:Special		ASCII Char: %c\n",input[i],input[i]);
	}
	return 0;
}
