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
		printf("need integer for the key , exit\n");
		return 1;
	}
	key = atoi(argv[1]);

//get input


	printf("plaintext: ");
	string plaintext = get_string();

	int length = strlen(plaintext);
	for (int i = 0; i < length; ++i)
	{
		if (isalpha(plaintext[i]) == false)
		{
			printf("%c", plaintext[i]);
		}
		else
		{
			if (isupper(plaintext[i]) == true)
			{
				printf("%c\n", ((int)plaintext[i] - 65 + key) % 26 + 65);
			}
			else
			{
				printf("%c\n", ((int)plaintext[i] - 97 + key) % 26 + 97);
			}
		}
	}

	printf("\n");
	return 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}