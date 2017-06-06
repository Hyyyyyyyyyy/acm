#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 100;
int ar[maxn];
int C[maxn];
int sum(int x)
{
	int s = 0;
	while (x)
	{
		s += C[x];
		x -= x & (-x);
	}
	return s;
}
void update(int x, int val, int n)
{
	while (x <= n)
	{
		C[x] += val;
		x += x & (-x);
	}
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF && n)
	{
		memset(C, 0, sizeof(C));
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			update(a, 1, n);
			update(b + 1, -1, n);
		}
		for (i = 1; i <= n; i++)
		{
			if (i != 1)
				putchar(' ');
			printf("%d", sum(i));
		}
		putchar('\n');
	}
	return 0;
}