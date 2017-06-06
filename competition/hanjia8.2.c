#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int i, j, u, n, m, N, A, B, x, cnt, sum;
	char k;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		for (m = 1; m <= n; m++)
		{
			cnt = 0;
			sum = 0;
			scanf("%c %d %d %d", &k, &N, &A, &B);
			getchar();
			if (k == 'k')
				cnt++;
			x = (int)k;
			for (i = 1; i <= N; i++)
			{
				if ((x = ((x - 97) * A + B * i) % 26 + 97) == 107)
				{
					cnt++;
					if (cnt == 7)
					{
						sum++;
						cnt = 0;
					}
				}
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}