#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 110;
typedef long long ll;
int ar[maxn][maxn];
int sa[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(sa, 0, sizeof(sa));
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%d", &ar[i][j]);
				if (ar[i][j])
				{
					sa[j]++;
				}
			}
		}
		for (i = 1; i <= m; i++)
		{
			if (i != 1)
				putchar(' ');
			printf("%d", sa[i]);
		}
		putchar('\n');
	}
	return 0;
}