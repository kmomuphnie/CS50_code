#include <stdio.h>
#include <cs50.h>
int qweasdzxc();

int main(void)
{
	int shower = 0;
	int bottle = 0;
	
	
	printf("Minutes: ");

	shower = get_int();
	// scanf(" %d", &shower);
	bottle = shower * 12;
	printf("bottles: %d\n", bottle);
}

// int qweasdzxc(){
// 	int a = 0;
// 	scanf("%d", &a);
// 	return a;
// }


