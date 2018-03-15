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
const ll MOD = 100000007ll;
const int maxn = 50000 + 100;
const int maxm = 100000 + 100;
ll dp[40][40];
void init()
{
	ll i, j, k;
	for (i = 0; i <= 30; i++)
		dp[1][i] = i + 1;
	for (i = 2; i <= 30; i++)
	{
		for (j = 0; i+j <= 30; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
			}
		}
	}
}
int main()
{
	init();
	ll i, j, N;
	while (scanf("%lld", &N) != EOF && N)
	{
		printf("%lld\n", dp[N][0]);
	}
	return 0;
}
