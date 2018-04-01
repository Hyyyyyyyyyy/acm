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
const int maxn = 1000000 + 100000;
const int maxm = 1000000 + 100;
struct Node
{
	int l;
	int r;
	int num;
	Node() {}
	Node(int a, int b, int c) : l(a), r(b), num(c) {}
};
Node G[maxn];
int tot;
int sum[maxn];
int N;
void build(int root, int k, int dep)
{
	if (tot < dep)
		tot = dep;
	if (G[root].num == -1)
	{
		G[root].num = k;
		sum[dep]++;
		return;
	}
	if (k < G[root].num)
	{
		G[root].r = root * 2 + 1;
		build(root * 2 + 1, k, dep + 1);
	}
	else
	{
		G[root].l = root * 2;
		build(root * 2, k, dep + 1);
	}
}
void Print(int root)
{
	queue<int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		if (now > 1)
			printf(" ");
		printf("%d", G[now].num);
		if (G[now].l != -1)
			Q.push(G[now].l);
		if (G[now].r != -1)
			Q.push(G[now].r);
	}
	printf("\n");
}
int main()
{
	int i, j, k;
	while (scanf("%d", &N) != EOF)
	{
		tot = 1;
		memset(sum, 0, sizeof(sum));
		for (i = 1; i <= (1 << N); i++)
		{
			G[i].l = G[i].r = G[i].num = -1;
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &k);
			build(1, k, 1);
		}
		Print(1);
		for (i = 1; i <= tot; i++)
		{
			if (sum[i] < (1 << (i - 1)) && i != tot)
			{
				printf("NO\n");
				break;
			}
		}
		if (i > tot)
		{
			for(j = (1 << (tot-1)); j <= N; j++)
            {
                if(G[j].num == -1)
                {
                    printf("NO\n");
                    break;
                }
            }
            if(j > N)
                printf("YES\n");
		}
	}
	return 0;
}
