#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{

	int key = 0;
	// char plaintext[];
	// char ciphertext[];

	if (argc != 2)
	{
		printf("A password's hash is needed, exit\n");
		return 1;
	}
	
	
	
	key = atoi(argv[1]);

	printf("plaintext:  ");
	string plaintext = get_string();
    
    printf("ciphertext: ");
    
	int length = strlen(plaintext);
	for (int i = 0; i < length; ++i)
	{
		if ( (isalpha(plaintext[i]) == 0) )
		{
			printf("%c", plaintext[i]);
		}
		else
		{   
		  //  bool up = isupper(plaintext[i]);
			if (isupper(plaintext[i]) != 0)
			{
				printf("%c", ((int)plaintext[i] - 65 + key) % 26 + 65);
			}
			else
			{
				printf("%c", ((int)plaintext[i] - 97 + key) % 26 + 97);
			}
		}
	}


// 	for (int i = 0; i < length; ++i)
// 	{
// 		if (isalpha(plaintext[i]) == false)
// 		{
// 			printf("%c", plaintext[i]);
// 		}
// 		else
// 		{   
// 		    bool up = isupper(plaintext[i]);
// 			if (up)
// 			{
// 				printf("%c", ((int)plaintext[i] - 65 + key) % 26 + 65);
// 			}
// 			else
// 			{
// 				printf("%c", ((int)plaintext[i] - 97 + key) % 26 + 97);
// 			}
// 		}
// 	}
	
	
	printf("\n");
	return 0;
}
