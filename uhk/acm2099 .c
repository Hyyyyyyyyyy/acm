#include <stdio.h>
int main()
{
	int n, m, a, b;
	bool doudou = false;

	while (scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0)
	{
		doudou = false;
		for (a = 0; a <= 9; a++)
		{
			for (b = 0; b <= 9; b++)
			{
				if ((n * 100 + a * 10 + b) % m == 0)
				{
					if (doudou)
						putchar(' ');
					doudou = true;
					if (a == 0 && b == 0)
						printf("00");
					else if (a == 0 && b != 0)
						printf("0%d", b);
					else
						printf("%d", a * 10 + b);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
