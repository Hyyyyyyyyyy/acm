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
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int A, B, N;
int ar[maxn];
int dp[maxn][maxn][maxn];
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d %d", &A, &B, &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			for (i = 0; i <= A; i++)
			{
				for (j = 0; j <= B; j++)
				{
					dp[i][j][0] = 100;
				}
			}
			int flag, doudou;
			int res = 0;
			doudou = 0;
			for (k = 1; k <= N; k++)
			{
				doudou = 0;
				for (i = 0; i <= A; i++)
				{
					for (j = 0; j <= B; j++)
					{
						dp[i][j][k] = dp[i][j][k - 1] - ar[k];
						if (i - 1>=0 && dp[i - 1][j][k - 1] - ar[k] < 70 && dp[i - 1][j][k - 1] - ar[k] > 0)
							dp[i][j][k] = max(dp[i][j][k], 70);
						if (i - 1>=0 && j - 1>=0 && dp[i - 1][j - 1][k - 1] - ar[k] < 70 && dp[i - 1][j - 1][k - 1] - ar[k] > 0)
							dp[i][j][k] = max(dp[i - 1][j - 1][k - 1], 100);
						if (j - 1>=0 && dp[i][j - 1][k - 1] - ar[k] > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] - ar[k] + 30);
						if (j - 2>=0 && dp[i][j - 2][k - 1] - ar[k] > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 2][k - 1] - ar[k] + 60);
						if (j - 3>=0 && dp[i][j - 3][k - 1] - ar[k] > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 3][k - 1] - ar[k] + 90);
						if (j - 4>=0 && dp[i][j - 4][k - 1] - ar[k] > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 4][k - 1] - ar[k] + 120);
						if (dp[i][j][k] > 100)
							dp[i][j][k] = 100;
						if (dp[i][j][k] > 0)
							doudou = 1;
					}
				}
				if (doudou)
					res++;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
//3维dp
//什么都不用，只用一个包，用一个包一个药，用一个药，用2个药，用3个药，用4个药