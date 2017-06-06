#include "headmark.h"
int main()
{
	int year, n;

	printf("Please choose the function:\n");
	printf("1.Is it a leapyear\n2.The Jan.1th is weekth\n3.Over!\n");
	while (scanf("%d", &n) != EOF)
	{
		switch (n)
		{
		case 1:
		{
			printf("Please enter a year you want to check:\n");
			while (scanf("%d", &year) != EOF)
			{
				if (year > 1000 && year < 9999)
				{
					if (leapyear(year))
						printf("Oh, it is a leapyear!\n");
					else
						printf("Um... it is not a leapyear.\n");
					break;
				}
				else
					printf("Illeagel year, please enter again:\n");
			}
			break;
		}
		case 2:
		{
			printf("Please enter a year you want to check:\n");
			while (scanf("%d", &year) != EOF)
			{
				if (year > 1000 && year < 9999)
				{
					weekth(year);
					break;
				}
				else
					printf("Illeagel year, please enter again:\n");
			}
			break;
		}
		case 3:
			printf("Bye!\n");
			break;
		}
		if (n == 3)
			break;
		else
			printf("Please  choose the function again:\n");
	}
	system("PAUSE");
	return 0;
}
