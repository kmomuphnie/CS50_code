#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int height = 0;
	printf("Height: ");
	height = get_int();

	while((height > 23) || (height < 0)){
	    printf("Height: ");
	    height = get_int();
	}

	for (int row = 1; row <= height; ++row)
	{
		for (int j = 0; j < (height - row); ++j)
		{
			printf(" ");
		}

		for (int j = 0; j < row; ++j)
		{
			printf("#");
		}
		printf("  ");

		for (int j = 0; j < row; ++j)
		{
			printf("#");
		}
// 		for (int j = 0; j < (height - row); ++j)
// 		{
// 			printf(" ");
// 		}
		printf("\n");
	}

	
	return 0;
}

