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
const int maxn = 1000 + 100;
const int maxm = 100000 + 100;
char s[maxn];
int N, M;
int ans[maxn];
int ar[maxn];   //原始数据
int dp[maxn][20];   //dp[i][j]表示以i开始连续j个元素的最值
					//转移：dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);     相当于把区间[i,2^j-1]分成[i,2^(j-1)-1]和[i+2^(j-1), 2^j-1];
int Log2[maxn];
int Min(int a, int b)
{
	return (ar[a] <= ar[b]) ? a : b;
}
void initRMQ(int n)
{
	Log2[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		Log2[i] = ((i & (i - 1)) == 0) ? (Log2[i - 1] + 1) : Log2[i - 1];
		dp[i][0] = i;
	}
	for (int j = 1; j <= Log2[n]; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			dp[i][j] = Min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int queryRMQ(int b, int e)
{
	int k = Log2[e - b + 1];
	return Min(dp[b][k], dp[e - (1 << k) + 1][k]);
}
int main()
{
	int i, j, n, m, top;
	while (scanf("%s %d", s, &M) != EOF)
	{
		N = strlen(s);
		for (i = 0; i < N; i++)
		{
			ar[i + 1] = (int)(s[i] - '0');
		}
		initRMQ(N);
		int top = 1;
		for (i = 1; i <= N - M; i++)
		{
			ans[i] = queryRMQ(top, M + i);
			top = ans[i] + 1;
		}
		bool doudou = true;
		for (i = 1; i <= N - M; i++)
		{
			if (ar[ans[i]] == 0 && doudou)
				continue;
			else
				printf("%d", ar[ans[i]]), doudou = false;
		}
		if (doudou)
			printf("0\n");
		else
			printf("\n");
	}
	return 0;
}