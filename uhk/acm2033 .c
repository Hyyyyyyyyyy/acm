#include <stdio.h>
int main()
{
	int n, m, i, u, hour1, hour2, minute1, minute2, second1, second2, second, minute, hour;

	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d %d %d %d", &hour1, &minute1, &second1, &hour2, &minute2, &second2);
			second = second1 + second2;
			minute = minute1 + minute2;
			hour = hour1 + hour2;
			if (second >= 60)
			{
				minute += second / 60;
				second %= 60;
			}
			if (minute >= 60)
			{
				hour += minute / 60;
				minute %= 60;
			}
			printf("%d %d %d\n", hour, minute, second);
		}
	}
	return 0;
}
