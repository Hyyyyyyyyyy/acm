#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000 + 10;
int c1[maxn][maxn];
int ar[maxn][maxn];
int N, M;
char s[10];
void update(int x, int y, int t)
{
	int i, j;
	for (i = x; i <= 1001; i += i & -i)
	{
		for (j = y; j <= 1001; j += j & -j)
		{
			c1[i][j] += t;
			if (c1[i][j] < 0)
				c1[i][j] = 0;
		}
	}
}
int sum(int x, int y)
{
	int res = 0;
	for (int i = x; i >= 1; i -= i & -i)
	{
		for (int j = y; j >= 1; j -= j & -j)
		{
			res += c1[i][j];
		}
	}
	return res;
}
int main()
{
	int i, j, k, u, n, m, a, b, c, d;
	while (scanf("%d", &n) != EOF)
	{
		memset(c1, 0, sizeof(c1));
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= n; i++)
		{
			scanf("%s", s);
			if (s[0] == 'B')
			{
				scanf("%d %d", &a, &b);
				a++;
				b++;
				if(!ar[a][b])
					update(a, b, 1);
				ar[a][b] = 1;
			}
			else if (s[0] == 'D')
			{
				scanf("%d %d", &a, &b);
				a++;
				b++;
				if(ar[a][b])
					update(a, b, -1);
				ar[a][b] = 0;
			}
			else
			{
				scanf("%d %d %d %d", &a, &c, &b, &d);
				if (a > c)
					swap(a, c);
				if (b > d)
					swap(b, d);
				a++;
				b++;
				c++;
				d++;
				printf("%d\n", sum(c, d) - sum(a-1, d) - sum(c, b-1) + sum(a-1, b-1));
			}
		}
	}
	return 0;
}