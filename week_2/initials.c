#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	string name = get_string();
	int length = strlen(name);

	//judge the start of the string

	int start = 0;
	while(name[start] == ' '){
		start = start + 1;
	}

	printf("%c", toupper((int)name[start]));
	for (int current = start + 1; (current < length) ; ++current)
	{
		if (name[current] == ' ')
		{
			int adder = 0;
			while((name[current + adder] == ' ') && (name[current+ adder+1] != '\0')){
				adder = adder + 1;
			}

			current = current + adder;
			if(name[current] != ' '){
				printf("%c", toupper((int)name[current]));
			}
		}
	}
	printf("\n");
	return 0;
}