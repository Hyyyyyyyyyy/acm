#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, k, pre[20000], cur[20000], num[4];
	while (scanf("%d %d %d", &num[1], &num[2], &num[3]) != EOF && (num[1] != 0 || num[2] != 0 || num[3] != 0))
	{
		memset(pre, 0, sizeof(int) * 20000);
		memset(cur, 0, sizeof(int) * 20000);

		for (i = 0; i <= num[1]; i++)
			pre[i] = 1;

		for (i = 0; i <= num[1]; i++)
		{
			for (j = 0; j <= num[2]*2; j += 2)
			{
				cur[j + i] += pre[i];
			}
		}
		for (i = 0; i <= num[2] * 2+num[1]; i++)
		{
			pre[i] = cur[i];
			cur[i] = 0;
		}
		for (i = 0; i <= num[2]*2+num[1]; i++)
		{
			for (j = 0; j <= num[3] * 5; j += 5)
			{
				cur[j + i] += pre[i];
			}
		}
		for (i = 1; i <= num[1] + num[2] * 2 + num[3] * 5 + 1; i++)
			if (cur[i] == 0)
				break;
		if (cur[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}
