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
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int N, K;
char res[maxn];
char str[maxn];
int fa[maxn];
char st[maxn];
int top;
int num[3];
bool vis[maxn];
bool comp()
{
	int L1 = strlen(res);
	int L2 = strlen(str);
	if (L1 != L2)
		return L1 > L2;
	for (int i = 0; i < L1; i++)
	{
		if (res[i] != str[i])
			return res[i] > str[i];
	}
	return false;
}
bool bfs(int n)
{
	int i, j, k;
	memset(vis, false, sizeof(vis));
	queue<int>Q;
	Q.push(0);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (i = 0; i < n; i++)
		{
			int after = (now*K + num[i]) % N;
			if (vis[after] || (now == 0 && num[i] == 0))
				continue;
			Q.push(after);
			fa[after] = now;
			st[after] = num[i] + '0';
			vis[after] = true;
			if (after == 0)
				return true;
		}
	}
	return false;
}
void getstr(int u)
{
	if (fa[u] != 0)
		getstr(fa[u]);
	str[top++] = st[u];
}
void update()
{
	int i;
	top = 0;
	getstr(0);
	str[top] = 0;
	if (strcmp(res, "#") == 0 || comp())
		for (i = 0; i < top; i++)
			res[i] = str[i];
	res[top] = 0;
}
int main()
{
	int i, j, k;
	while (scanf("%d %d", &N, &K) != EOF)
	{
		res[0] = '#';
		res[1] = 0;
		str[0] = 0;
		for (i = 1; i < K; i++)
		{
			num[0] = i;
			if (bfs(1))
			{
				update();
			}
		}
		if (strcmp(res, "#") == 0)
		{
			for (i = 0; i < K; i++)
			{
				for (j = i + 1; j < K; j++)
				{
					num[0] = i;
					num[1] = j;
					if (bfs(2))
					{
						update();
					}
				}
			}
		}
		printf("%s\n", res);
	}
	return 0;
}
//4294      至多两个数字就可以拼出任何数的倍数。
//证明可以这样，AAAA...AAA若干个A，模X，能得到的余数种类是有限的，至多是1~X - 1
//那么总会有n个A和m个A这两个数模X余数相等，他们相减就得到了X的倍数，而相减得到的数就是两个数组成的。