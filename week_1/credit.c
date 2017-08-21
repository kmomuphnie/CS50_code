#include <stdio.h>
#include <cs50.h>

int main(void)
{	
	printf("Number: ");
	long long number = get_long_long();

	while(number <= 0){
		printf("Number: ");
		number = get_long_long();
	}
	if (number <= 1000000000000)
	{
		printf("INVALID\n");
		return 0;
	}


	int totalSum = 0;
	int secondSum = 0;
	int digit = 0;
	int firstSum = 0;
	long long copy = number;
//add every second digits
	while(copy != 0){
		digit = (copy / 10) -((copy / 100) * 10);
		digit = digit * 2;
		// printf("%d\n", digit);
		if (digit > 9)
		{
			secondSum = secondSum + (digit % 10) + digit / 10;
			// printf("%d\n", secondSum);
		}else{
			secondSum = secondSum + digit;
			// printf("%d\n", secondSum);
		}
		copy = copy / 100;
	}
//add every first digits

	copy = number;
	while(copy != 0){
		digit = copy - (copy / 10) * 10;
		firstSum = firstSum + digit;
		copy = copy / 100;
	}	
	
	
	
	// printf("%d\n", secondSum);
	totalSum = firstSum + secondSum;
	if ( (totalSum - (totalSum / 10) * 10) != 0)
	{
		printf("INVALID\n");
		return 0;
	}else{
		if ((number / 10000000000000) == 0)
		{
			printf("VISA\n");
			return 0;
		}
		if ((number / 1000000000000000) == 0)
		{
			printf("AMEX\n");
			return 0;
		}else 
		{
			if ((number / 1000000000000000) == 5 )
			{
				printf("MASTERCARD\n");
				return 0;
			}else{
				printf("VISA\n");
				return 0;
			}
		}
	}

	return 0;
}
