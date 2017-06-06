#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
const int MAX = 100000000;
const int MIN = -10000000;
using namespace std;
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int i, j, k, u, n, m, ar[2010], bag[2010][1010];
	while (scanf("%d %d", &n, &k) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
		}
		sort(ar + 1, ar + n + 1, comp);
		for (i = 0; i <= n; i++)
		{
			for (j = 1; j <= k; j++)
			{
				bag[i][j] = MAX;
			}
		}
		for (i = 0; i <= k; i++)
			bag[i][0] = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= k && i >= 2 * j; j++)
			{
				bag[i][j] = (bag[i - 1][j] < bag[i - 2][j - 1] + (ar[i] - ar[i - 1]) * (ar[i] - ar[i - 1])) ? bag[i - 1][j] : (bag[i - 2][j - 1] + (ar[i] - ar[i - 1]) * (ar[i] - ar[i - 1]));
			}
		}
		printf("%d\n", bag[n][k]);
	}
	return 0;
}