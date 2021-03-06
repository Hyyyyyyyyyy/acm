//笛卡尔树是一棵二叉树，树的每个节点有两个值，一个为key，一个为value。
//光看key(第一关键字)的话，笛卡尔树是一棵二叉搜索树，每个节点的左子树的key都比它小，右子树都比它大；
//光看value(第二关键字)的话，笛卡尔树有点类似堆，根节点的value是最小（或者最大）的，每个节点的value都比它的子树要大。
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
	int pre;
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
int Stack[maxn];
char road[maxn];
bool vis[maxn];
int rq[maxn];   //深搜容器，非递归写dfs
int build_dkaer_tree()     //按值（第一关键字）从小到大排序，对标号（第二关键字）建树
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
	memset(vis, false, sizeof(vis));
	int top = 0;
	rq[++top] = root;
	while (!vis[root])
	{
		int u = rq[top];
		road[tol++] = (u & 1 ? '1' : '0');
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
	//latter[tol++] = (node[root].num & 1 ? '1' : '0');
	//if (node[root].l != -1)
	//{
	//	dfs(node[root].l);
	//	latter[tol++] = (node[root].num & 1 ? '1' : '0');
	//}
	//if (node[root].r != -1)
	//{
	//	dfs(node[root].r);
	//	latter[tol++] = (node[root].num & 1 ? '1' : '0');
	//}
	return;
}
char s[maxn];
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
			}
			scanf("%s", s);
			sort(node + 1, node + 1 + N, comp);
			int root = build_dkaer_tree();
			tol = 0;
			dfs(root);
			road[tol] = 0;
			puts(road);
		}
	}
	return 0;
}