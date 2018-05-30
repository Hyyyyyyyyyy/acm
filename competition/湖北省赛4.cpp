#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e7 + 7;
const int maxn = 2000 + 100;
const int maxm = 1000000 + 100;
int N, M;
int ar[maxn][maxn];
int main()
{
	int i, j, k, m;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		int x, y, L;
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d %d", &x, &y, &L);
			for (i = x; i < x+L; i++)
			{
				for (j = y; j < y+ L; j++)
				{
					int temp1 = ar[i][j + L];
					int temp2 = ar[i + L][j + L];
					int temp3 = ar[i + L][j];
					int temp4 = ar[i][j];
					ar[i][j + L] = ar[i][j];
					ar[i + L][j + L] = temp1;
					ar[i + L][j] = temp2;
					ar[i][j] = temp3;
				}
			}
		}
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				ar[i][j] += max(ar[i - 1][j], ar[i][j - 1]);
			}
		}
		printf("%d\n", ar[N][N]);
	}
	return 0;
}