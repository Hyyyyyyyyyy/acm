#include <stdio.h>
#include <string.h>
int main()
{
	int n, m;
	long long sum, halfsum, i, j, k, num[1005], value[55], pre[260000], cur[260000];
	while (scanf("%d", &n) != EOF && n > 0)
	{
		sum = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &value[m], &num[m]);
			sum += num[m] * value[m];
		}
		halfsum = sum / 2;
		memset(pre, 0, sizeof(long long)*260000);
		memset(cur, 0, sizeof(long long)*260000);
		for (i = 0; i <= num[1] * value[1]; i += value[1])
			pre[i] = 1;
		for (i = 2; i <= n; i++)
		{
			for (j = 0; j <= halfsum; j++)
			{

				for (k = 0; k <= num[i] * value[i] && k + j <= halfsum; k += value[i])
					cur[k + j] += pre[j];
			}

			for (j = 0; j <= halfsum; j++)
			{
				pre[j] = cur[j];
				cur[j] = 0;
			}
		}
		
        for (i = halfsum; i >= 0; i--)
        {
            if (pre[i])
            {
                if (i <= sum - i)
                    printf("%lld %lld\n", sum-i, i);
                else
                    printf("%lld %lld\n", i, sum - i);
                break;
            }
        }
		
	}
	return 0;
}
