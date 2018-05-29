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
const int maxn = 600000 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	int l;
	int r;
	int id;
	int num;
};
Node node[maxn];
bool comp(Node &a, Node &b)
{
	return a.num < b.num;
}
int N;
int tol;
int ar[maxn];
int Stack[maxn];
char former[7010], latter[maxn*3];
int Next[7010];
int rq[maxn], vis[maxn];
void GETnext()      //有优化
{
	int i, j, k;
	int L = strlen(former);
	Next[0] = -1;
	i = 0;
	j = -1;
	while (i < L && j < L)
	{
		if (j == -1 || former[i] == former[j])
		{
			i++;
			j++;
			//优化
			if (former[i] == former[j])
				Next[i] = Next[j];
			else
				Next[i] = j;
			//如果不要优化，这样：
			//Next[i] = j;
		}
		else
			j = Next[j];
	}
}
int KMP()       //返回目标串在主串中出现的次数
{
	int i, j;
	GETnext();
	int L1 = strlen(former);
	int L2 = strlen(latter);
	i = 0;
	j = 0;
	int res = 0;
	while (i < L2)
	{
		while (-1 != j && latter[i] != former[j])
			j = Next[j];
		i++;
		j++;
		if (j >= L1)
		{
			res++;
			j = Next[j];
		}
	}
	return res;
}
int build_dkaer_tree()
{
	int i, j, k;
	int temp;
	int top = -1;
	for (i = 1; i <= N; i++)		//i是第一关键字
	{
		temp = top;
		while (top >= 0 && node[Stack[temp]].id > node[i].id)		//id是第二关键字
			temp--;

		if (temp != -1)
		{
			node[Stack[temp]].r = i;
		}
		if (temp < top)
		{
			node[i].l = Stack[temp + 1];
		}
		Stack[++temp] = i;
		top = temp;
	}
	return Stack[0];
}
void dfs(int root)
{
	memset(vis, 0, sizeof(vis));
	int top = 0;
	rq[++top] = root;
	while (!vis[root])
	{
		int u = rq[top];
		latter[tol++] = (u & 1 ? '1' : '0');
		int v = node[u].l;
		if (v != -1 && !vis[v])
		{
			rq[++top] = v;
			continue;
		}
		v = node[u].r;
		if (v != -1 && !vis[v])
		{
			rq[++top] = v;
			continue;
		}
		top--;
		vis[u] = 1;
	}
}
int main()
{
	int i, j, k, CAS, cas;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &node[i].num);
				node[i].id = i;
				node[i].l = node[i].r = -1;
				ar[i] = node[i].num;
			}
			scanf("%s", former);
			sort(node + 1, node + 1 + N, comp);
			int root = build_dkaer_tree();
			tol = 0;
			dfs(root);
			latter[tol] = 0;
			printf("Case #%d: %d\n", cas, KMP());
		}
	}
	return 0;
}
