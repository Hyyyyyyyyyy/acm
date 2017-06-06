#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1100;
const double eps = 1.0e-9;
struct Node
{
	int l;
	int r;
	int mid;
	int sta;
	double len;
};
Node ar[maxn * 4];
struct Edge
{
	double l;
	double r;
	double h;
	int f;
};
Edge edge[maxn * 3];
bool comp(Edge& a, Edge& b)
{
	return a.h < b.h;
}
double sep[maxn * 2];
int cnt, N;
void pushup(int root)
{
	if (ar[root].sta > 0)
	{
		ar[root].len = sep[ar[root].r + 1] - sep[ar[root].l];
	}
	else if (ar[root].r == ar[root].l)
	{
		ar[root].len = 0;
	}
	else
	{
		ar[root].len = ar[root * 2].len + ar[root * 2 + 1].len;
	}
}
void build(int root, int begin, int end)
{
	ar[root].l = begin;
	ar[root].r = end;
	ar[root].mid = (begin + end) / 2;
	ar[root].sta = 0;
	ar[root].len = 0;
	if (begin == end)
	{
		return;
	}
	build(root * 2, ar[root].l, ar[root].mid);
	build(root * 2 + 1, ar[root].mid + 1, ar[root].r);
}
void update(int root, int begin, int end, int val)
{
	if (begin <= ar[root].l && ar[root].r <= end)
	{
		ar[root].sta += val;
		pushup(root);
		return;
	}
	if (begin <= ar[root].mid)
		update(root * 2, begin, end, val);
	if (end > ar[root].mid)
		update(root * 2 + 1, begin, end, val);
	pushup(root);
}
int tp_search(int root, double x)
{
	int l = ar[root].l;
	int r = ar[root].r;
	int mid;
	while (r >= l)
	{
		mid = (l + r) / 2;
		if (fabs(sep[mid] - x) < eps)
			return mid;
		if (sep[mid] > x)
			r = mid - 1;
		else if (sep[mid] < x)
			l = mid + 1;
	}
}
int main()
{
	int i, j, k, u, n, m, cas = 1;
	double x1, x2, y1, y2;
	while (scanf("%d", &n) != EOF && n)
	{
		cnt = 1;
		for (m = 1; m <= n; m++)
		{
			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			sep[cnt] = x1;
			edge[cnt].l = x1;
			edge[cnt].r = x2;
			edge[cnt].h = y1;
			edge[cnt++].f = 1;
			sep[cnt] = x2;
			edge[cnt].l = x1;
			edge[cnt].r = x2;
			edge[cnt].h = y2;
			edge[cnt++].f = -1;
		}
		cnt--;
		sort(edge + 1, edge + cnt + 1, comp);
		sort(sep + 1, sep + cnt + 1);
		N = 2;
		for (i = 2; i <= cnt; i++)
		{
			if (sep[i] != sep[i - 1])
				sep[N++] = sep[i];
		}
		N--;
		build(1, 1, N);
		double res = 0;
		for (i = 1; i <= cnt; i++)
		{
			int L = tp_search(1, edge[i].l);
			int R = tp_search(1, edge[i].r) - 1;
			update(1, L, R, edge[i].f);
			res += ar[1].len * (edge[i + 1].h - edge[i].h);
		}
		printf("Test case #%d\n", cas++);
		printf("Total explored area: %.2f\n\n", res);
	}
	return 0;
}