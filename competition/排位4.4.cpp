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
const int maxn = 100000 + 10;
const int maxm = 1000000 + 100;
ll N, A;
ll ar[maxn];
ll dp[2][1 << 8][3];
int main()
{
	ll i, j, k, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &A);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			for (j = 0; j < (1 << 8); j++)
			{
				for (k = 0; k < 3; k++)
				{
					dp[1][j][k] = dp[0][j][k] = 0;
				}
			}
			dp[0][ar[1]][0] = dp[0][ar[1]][1] = dp[0][ar[1]][2] = 1;
			for (i = 0, j = 2; j <= N; j++, i ^= 1)
			{
				for (k = 0; k < (1 << 8); k++)
				{
					//j == 0
					dp[i ^ 1][k ^ ar[i + 1]][0] += dp[i][k][0];
					dp[i ^ 1][k ^ ar[i + 1]][0] %= MOD;
					dp[i ^ 1][k ^ ar[i + 1]][1] += dp[i][k][0];
					dp[i ^ 1][k ^ ar[i + 1]][1] %= MOD;
					dp[i ^ 1][k ^ ar[i + 1]][2] += dp[i][k][0];
					dp[i ^ 1][k ^ ar[i + 1]][2] %= MOD;
					//j == 1
					if (k + ar[i + 1] <= A)
					{
						dp[i ^ 1][k + ar[i + 1]][0] += dp[i][k][1];
						dp[i ^ 1][k + ar[i + 1]][0] %= MOD;
						dp[i ^ 1][k + ar[i + 1]][1] += dp[i][k][1];
						dp[i ^ 1][k + ar[i + 1]][1] %= MOD;
						dp[i ^ 1][k + ar[i + 1]][2] += dp[i][k][1];
						dp[i ^ 1][k + ar[i + 1]][2] %= MOD;
					}
					//j == 2
					dp[i ^ 1][k | ar[i + 1]][0] += dp[i][k][2];
					dp[i ^ 1][k | ar[i + 1]][0] %= MOD;
					dp[i ^ 1][k | ar[i + 1]][1] += dp[i][k][2];
					dp[i ^ 1][k | ar[i + 1]][1] %= MOD;
					dp[i ^ 1][k | ar[i + 1]][2] += dp[i][k][2];
					dp[i ^ 1][k | ar[i + 1]][2] %= MOD;
				}
			}
			printf("%lld\n", max(dp[i][A][0], max(dp[i][A][1], dp[i][A][2])) % MOD);
		}
	}
	return 0;
}
