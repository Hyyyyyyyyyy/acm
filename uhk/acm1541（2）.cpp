#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 32000 + 5;
int c[maxn], res[15100];
int ar[15100], sa[15100];
void update(int x, int y)
{
	int i, j;
	for (i = x; i <= maxn; i += (i & (-i)))
	{
		c[i]++;
	}
}
int sum(int x, int y)
{
	int i, j, r = 0;
	for (i = x; i; i -= (i & (-i)))
	{
		r += c[i];
	}
	return r;
}
int main()
{
	int i, j, k, u, n, m, a, b, maxx, maxy;
	while (scanf("%d", &n) != EOF)
	{
		maxx = -1;
		maxy = -1;
		memset(c, 0, sizeof(c));
		memset(res, 0, sizeof(res));
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &ar[i], &sa[i]);
			ar[i]++;
			res[sum(ar[i], sa[i])]++;
			update(ar[i], sa[i]);
		}
		for (i = 0; i <= n - 1; i++)
			printf("%d\n", res[i]);
	}
	return 0;
}
