#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define foR for
#define for9 for
typedef long long ll;
typedef unsigned long long ull;
const int inf = (1ll << 31) - 1;
const ll INF = (1ull << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int ar[maxn][maxn], sa[maxn][maxn];
int N;
int main()
{
	int i, j, k, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		foR(m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			foR(i = 1; i <= N; i++)
			{
				foR(j = 1; j <= N; j++)
				{
					scanf("%d", &ar[i][j]);
					sa[i][j] = ar[i][j];
				}
			}
			bool doudou = true;
			int num = 0;
			for9(i = 1; i <= N; i++)
			{
				for (j = 1; j <= N; j++)
				{
					for (k = 1; k <= N; k++)
					{
						if (sa[i][k] + sa[k][j] < sa[i][j])
						{
							doudou = false;
						}
						else if (sa[i][k] + sa[k][j] == sa[i][j] && sa[i][k] && sa[k][j])
						{
                            num++;
                            break;
						}
					}
				}
			}

			if (doudou)
			{
				printf("Case %d: %d\n", m, N*(N - 1) - num);
			}
			else
			{
				printf("Case %d: impossible\n", m);
			}
		}
	}
	return 0;
}