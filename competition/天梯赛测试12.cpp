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
const ll MOD = 1000000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	int fa;
	int mo;
	int sex;
	int id;
	Node() {
		fa = -1;
		mo = -1;
	}
	Node(int a, int b, int c, int d) : fa(a), mo(b), sex(c), id(d) {}
};
Node G[maxn];
int dfs(int x, int y, int dep)
{
	if (dep >= 5)
		return 0;
	if (x == -1 || y == -1)
		return 0;
	if ((G[x].mo != -1 && G[x].mo == G[y].mo) || (G[x].fa != -1 && G[x].fa == G[y].fa))
		return 1;
	return (dfs(G[x].mo, G[y].mo, dep + 1) || dfs(G[x].mo, G[y].fa, dep + 1) || dfs(G[x].fa, G[y].mo, dep + 1) || dfs(G[x].fa, G[y].fa, dep + 1));
}
int main()
{
	int i, j, k, a, b, c, N, Q;
	char s[5];
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d %s %d %d", &a, s, &b, &c);
			G[a] = Node(b, c, (s[0] == 'M' ? 0 : 1), a);
			if(b != -1)
				G[b].sex = 0;
			if(c != -1)
				G[c].sex = 1;
		}
		scanf("%d", &Q);
		for (int q = 1; q <= Q; q++)
		{
			scanf("%d %d", &a, &b);
			if (G[a].sex == G[b].sex)
				printf("Never Mind\n");
			else if (dfs(a, b, 1))
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}