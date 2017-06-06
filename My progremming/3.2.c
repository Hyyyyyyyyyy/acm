#include <stdio.h>
int main()
{
	int ten = 10;
	int two = 2;
	int a = ten - two;
	
	printf("Doing it right:");
	printf("%d minus %d is %d\n", ten, two, a);
	printf("Doing it wrong:");
	printf("%d minus %d is %d\n", 2);
	
	getchar();
	return 0;
}
