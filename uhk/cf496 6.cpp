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
const int maxn = 300000 + 100;
const int maxm = 1000000 + 100;
int S[maxn * 2];
int N, M;
int ar[maxn];
ll solve(int m)
{
	int i, j;
	memset(S, 0, sizeof(S));
	ll res = 0;
	S[N] = 1;
	int sum = N;
	ll add = 0;
	for (i = 1; i <= N; i++)
	{
		if (ar[i] < m)
		{
			sum--;
			add -= S[sum];
		}
		else
		{
			add += S[sum];
			sum++;
		}
		res += add;
		S[sum]++;
	}
	return res;
}
int main()
{
	int i, j, k, sum;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		printf("%I64d\n", solve(M) - solve(M + 1));
	}
	return 0;
}
//S[i]表示枚举到当前位置中位数比M大i的组数有多少组
//solve(m)表示中位数大于等于m的组数，结果就是solve(m)-solve(m+1)