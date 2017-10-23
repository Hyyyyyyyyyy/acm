#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e18;
const int maxn = 100000 + 100;
struct Node
{
	int l;
	int r;
	int mid;
	int max;
	int id;
};
Node ar[maxn];
Node G[maxn * 4];
void pushup(int root)
{
	G[root].max = max(G[root * 2].max, G[root * 2 + 1].max);
}
void build(int root, int begin, int end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	G[root].max = 0;
	if (begin == end)
		return;
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
}
void update(int root, int index, int val)
{
	if (G[root].l == G[root].r && G[root].l == index)
	{
		G[root].max = val;
		return;
	}
	if (index <= G[root].mid)
		update(root * 2, index, val);
	else
		update(root * 2 + 1, index, val);
	pushup(root);
}
int query(int root, int b, int e)
{
	if (b <= G[root].l && G[root].r <= e)
	{
		return G[root].max;
	}
	int res = 0;
	if (b <= G[root].mid)
		res = max(res, query(root * 2, b, e));
	if (e > G[root].mid)
		res = max(res, query(root * 2 + 1, b, e));
	return res;
}
bool comp1(const Node& a, const Node& b)
{
	return a.l < b.l;
}
bool comp2(const Node& a, const Node& b)
{
	return a.id < b.id;
}
int sa[maxn];
int res[maxn];      //res[i]是以i位置为结尾的最长上升区间和
int main()
{
	int i, j, k, u, n, m, N;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &ar[i].l, &ar[i].r);
			ar[i].id = i;
		}
		sort(ar + 1, ar + 1 + N, comp1);
		int cnt = 0;
		ar[0].r = -INF;
		for (i = 1; i <= N; i++)
		{
			if (ar[i].r != ar[i - 1].r)
			{
				sa[ar[i].id] = i + 1;
			}
			else    //去重   此题输入区间不会有重叠 但是会重复
			{
				sa[ar[i].id] = sa[ar[i - 1].id];
			}
		}
		sort(ar + 1, ar + 1 + N, comp2);
		build(1, 1, N+1);
		int Max = -INF;
		for (i = 1; i <= N; i++)
		{
			res[i] = ar[i].r - ar[i].l + 1 + query(1, 1, sa[i] - 1);
			update(1, sa[i], res[i]);
			if (Max < res[i])
				Max = res[i];
		}
		printf("%d\n", Max);
	}
	return 0;
}