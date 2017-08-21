
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    if (argc != 2)
	{
		printf("need integer for the key , like Usage: ./crack hash\n");
		return 1;
	}
	
	char input[13];
	strcpy(input, argv[1]);
    string output;
	char salt[2] = {'5', '0'};
		
	char one[2];
	one[1] = '\0';
	char two[3];
	two[2] = '\0';
	char three[4];
	three[3] = '\0';	
	char four[5];
	four[4] = '\0';
	
	
	for (int i = 65; i < 123; ++i)
	{
		one[0] = (char)i;
		output = crypt (one, salt);
		if (strcmp(input, output) == 0)
		{
			printf("%s\n", one);
			return 0;
		}
	}
		// printf("1 not found\n");

	for (int i = 65; i < 123; ++i)
	{
		two[0] = (char)i;
		for (int j = 65; j < 123; ++j)
		{
			two[1] = (char)j;
			output = crypt (two, salt);
			if (strcmp(input, output) == 0)
			{
				printf("%s\n", two);
				return 0;
			}
		}		
	}
	// printf("2 not found\n");
	for (int i = 65; i < 123; ++i)
	{	
		three[0] = (char)i;
		for (int j = 65; j < 123; ++j)
		{
			three[1] = (char)j;
			for (int m = 65; m < 123; ++m)
			{
				three[2] = (char)m;
				output = crypt(three, salt);
				if (strcmp(input, output) == 0)
				{
					printf("%s\n", three);
					return 0;
				}
			}
		}
	}
		// printf("3 not found\n");
	for (int i = 65; i < 123; ++i)
	{	
		four[0] = (char)i;
		for (int j = 65; j < 123; ++j)
		{	
			four[1] = (char)j;
			for (int k = 65; k < 123; ++k)
			{	
				four[2] =  (char)k;
				for (int m = 65; m < 123; ++m)
				{
					four[3] = (char)m;
					output = crypt(four, salt);
					
					if (strcmp(input, output) == 0)
					{
						printf("%s\n", four);
						return 0;
					}

				}
			}
		}
	}	
	
	// printf("4 not found\n");
	// crypt (const char *key, const char *salt)
	// int strcmp(const char *str1, const char *str2)
	// printf("%s\n", input);
}