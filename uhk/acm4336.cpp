#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 20 + 5;
double dp[1 << maxn], ar[maxn];
int N;
double all;
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &N) != EOF)
	{
		all = 0.0;
		for (i = 1; i <= N; i++)
		{
			scanf("%lf", &ar[i]);
			all += ar[i];
		}
		all = 1.0 - all;
		dp[(1 << N) - 1] = 0;
		for (i = (1 << N) - 2; i >= 0; i--)
		{
			double x = 0.0;
			double sum = 1.0;
			for (j = 1; j <= N; j++)
			{
				if (i & (1 << (j - 1)))
				{
					x += ar[j];
				}
				else
				{
					sum += ar[j] * dp[i | (1 << (j - 1))];
				}
				dp[i] = sum / (1.0 - x - all);
			}
		}
		printf("%.5f\n", dp[0]);
	}
	return 0;
}