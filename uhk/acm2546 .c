#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, i, j, bag[1005], value[1005], money, max, temp, sum;
	while (scanf("%d", &n) != EOF && n != 0)
	{
        
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &value[m]);
		}

        scanf("%d", &money);
        if (money < 5)
		{
			printf("%d\n", money);
			continue;
		}
        
		for (i = 1; i <= n; i++)
		{
			if (value[n] < value[i])
			{
				temp = value[n];
				value[n] = value[i];
				value[i] = temp;
			}
		}

		memset(bag, 0, sizeof(int) * 1005);
		sum = 0;

		for (i = 1; i < n; i++)
		{
			for (j = money - 5; j >= value[i]; j--)
			{
				temp = bag[j - value[i]] + value[i];
				bag[j] = (bag[j] > temp) ? bag[j] : temp;
			}

		}
		printf("%d\n", money - bag[money-5] - value[n]);
	}
	return 0;
}
