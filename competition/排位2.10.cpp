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
const double inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
int w[10] = { 6,2,5,5,4,5,6,3,7,6 };
char s[maxn];
int dp[150][900];
int N;
int main()
{
	int i, j, k, cas, CAS;
	dp[0][0] = 1;
	for (i = 1; i <= 110; i++)  //最长100
	{
		for (j = 1; j <= 800; j++)  //最多7*100根管
		{
			for (k = 0; k <= 9; k++)    //如果该长度的位置取k这个数字，那么它的状态和i-1位置sum-w[k]根管的状态是一样的
			{                           //用 | 操作是因为0~9只要有一个数字在该位置满足就是1
				if (j < w[k])
					continue;
				dp[i][j] |= dp[i - 1][j - w[k]];
			}
		}
	}
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			scanf("%s", s + 1);
			int sum = 0;
			for (i = 1; i <= N; i++)
			{
				sum += w[s[i] - '0'];
			}
			for (i = 1; ; i++)
			{
				if (dp[i][sum])
					break;
			}
			int Len = i;
			for (i = 1; i <= Len; i++)
			{
				for (j = (i == 1 ? 1 : 0); j <= 9; j++)
				{
					if (dp[Len - i][sum - w[j]])
					{
						printf("%d", j);
						sum -= w[j];
						break;
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
//dp[i][j] 表示长度为i的数字能否用到j个发光LED管
//先预处理出所有可能长度和可能管子个数
//找出最短的能用sum根管子的数字长度
//从高位到低位枚举