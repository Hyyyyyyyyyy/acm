#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 10000;
int ar[maxn];
int main()
{
	int i, j, k, u, n, m, s, t;
	while (scanf("%d", &n) != EOF && n)
	{
		memset(ar, 0, sizeof(ar));
		int doudou = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &s, &t, &k);
			ar[s] += k;
			ar[t] -= k;
			if (s > t)
				doudou = 1;
		}
		int Max = -INF;
		if (!doudou)
		{
			for (i = 1; i <= 100; i++)
			{
				ar[i] += ar[i - 1];
				Max = max(Max, ar[i]);
			}
		}
		else
		{
			for (i = 100; i >= 1; i--)
			{
				ar[i] += ar[i + 1];
				Max = max(Max, ar[i]);
			}
		}
		printf("%d\n", Max);
	}
	printf("*\n");
	return 0;
}