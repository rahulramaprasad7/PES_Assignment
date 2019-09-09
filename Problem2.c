#include <stdio.h>
int main()
{
	char input[]={66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};
	
	for( int i = 0; i <(sizeof(input)/sizeof(char)); i++)
	{
		if( input[i] >= 'A' && input[i] <= 'Z' )                                           		//http://www.asciitable.com/ for checking ASCII range
			printf("Code: %d	Type:Upper Case 	ASCII Code: %c\n",input[i],input[i]);
		
		else if( input[i] >= 'a' && input[i] <= 'z' )
			printf("Code: %d	Type:Lower Case		ASCII Code: %c\n",input[i],input[i]);
			
		else if( input[i] >= '0' && input[i] <= '9' )
			printf("Code: %d	Type:Digit		ASCII Code: %c\n",input[i],input[i]);
		
	}
	return 0;
}