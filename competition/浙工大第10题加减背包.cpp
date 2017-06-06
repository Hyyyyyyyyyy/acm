#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int i, j, k, u, n, m, ar[110], dp[30010], sum, p, q;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &p);
			sum = 0;
			for (i = 1; i <= p; i++)
			{
				scanf("%d", &ar[i]);
				sum += ar[i];
			}
			for (i = 0; i <= sum * 2; i++)
			{
				dp[i] = -sum;
			}
			for (i = 1; i <= p; i++)
			{
				for (k = 1; k <= 2; k++)
				{
					for (j = 2 * sum; j >= ar[i]; j--)
					{
						dp[j] = (dp[j] > dp[j - ar[i]] + ar[i]) ? dp[j] : (dp[j - ar[i]] + ar[i]);
					}
				}
			}
			//for (i = 0; i <= sum * 2; i++)
			//	printf("%d ", dp[i]);
			//putchar('\n');
			scanf("%d", &k);
			for (i = 1; i <= k; i++)
			{
				scanf("%d", &q);
				if (dp[q+sum] == q)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}
