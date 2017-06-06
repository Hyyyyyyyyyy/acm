#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, set[2000], b, e, i, j, k, u, count;
	char begin[5], end[5];
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		memset(set, 0, sizeof(int) * 2000);
		for (m = 1; m <= n; m++)
		{
			scanf("%c%c:%c%c %c%c:%c%c", &begin[1], &begin[2], &begin[3], &begin[4], &end[1], &end[2], &end[3], &end[4]);
			getchar();
			b = ((begin[1]-48) * 10 + (begin[2]-48)) * 60 + (begin[3]-48) * 10 + begin[4] - 48;
			e = ((end[1]-48) * 10 + (end[2]-48)) * 60 + (end[3]-48) * 10 + (end[4]-48);
			for (i = b; i <= e; i++)
				set[i] = 1;
		}
		count = 0;
		for (i = 1; i <= 1440; i++)
		{
			if (set[i] == 0)
				count++;
			else if (set[i - 1] == 0)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
