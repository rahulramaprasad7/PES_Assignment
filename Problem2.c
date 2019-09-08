#include <stdio.h>
int main()
{
	int input[]={66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};
	
	for( int i = 0; i <(sizeof(input)/sizeof(int)); i++)
	{
		if( input[i] >= 65 && input[i] <=90 )                                           		//http://www.asciitable.com/ for checking ASCII range
			printf("Code: %d	Type:Upper Case 	ASCII Code: %c\n",input[i],input[i]);
		
		else if( input[i] >= 97 && input[i] <=122 )
			printf("Code: %d	Type:Lower Case		ASCII Code: %c\n",input[i],input[i]);
			
		else if( input[i] >= 48 && input[i] <=57 )
			printf("Code: %d	Type:Digit		ASCII Code: %c\n",input[i],input[i]);
		
	}
	return 0;
}