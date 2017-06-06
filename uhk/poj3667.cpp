#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int l;
	int r;
	int mid;
	int lx;
	int rx;
	int max;
	int visit;
};
node sa[50000 * 4];
int ar[50000 * 4];
int N, M;
void build(int root, int begin, int end);
void update(int root, int b, int e, int val);
void pushdown(int root);
void pushup(int root);
int query(int root, int num);
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		build(1, 1, N);
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d", &a, &b);
			if (a == 1)
			{
				if (sa[1].max < b)
				{
					printf("0\n");
					continue;
				}
				int x = query(1, b);
				printf("%d\n", x);
				update(1, x, x + b - 1, m);
			}
			else
			{
				scanf("%d", &c);
				update(1, b, b + c - 1, 0);
			}
		}
	}
	return 0;
}
void build(int root, int begin, int end)
{
	sa[root].l = begin;
	sa[root].r = end;
	sa[root].mid = (begin + end) / 2;
	sa[root].visit = -1;
	if (begin == end)
	{
		sa[root].lx = sa[root].rx = sa[root].max = 1;
	}
	else
	{
		build(root * 2, sa[root].l, sa[root].mid);
		build(root * 2 + 1, sa[root].mid + 1, sa[root].r);
		pushup(root);
	}
}
void pushup(int root)
{
	sa[root].lx = sa[root * 2].lx + ((sa[root * 2].lx == (sa[root].mid - sa[root].l + 1)) ? sa[root * 2 + 1].lx : 0);
	sa[root].rx = sa[root * 2 + 1].rx + ((sa[root * 2 + 1].rx == (sa[root].r - sa[root].mid)) ? sa[root * 2].rx : 0);
	sa[root].max = max(max(sa[root * 2].max, sa[root * 2 + 1].max), sa[root * 2].rx + sa[root * 2 + 1].lx);
}
void update(int root, int b, int e, int val)
{
	if (sa[root].l > e || sa[root].r < b)
		return;
	if (sa[root].l >= b && sa[root].r <= e)
	{
		sa[root].visit = val;
		if (val != 0)
			sa[root].lx = sa[root].rx = sa[root].max = 0;
		else
		{
			sa[root].rx =  sa[root].lx =  sa[root].max = sa[root].r - sa[root].l + 1;
		}
		return;
	}
	pushdown(root);
	update(root * 2, b, e, val);
	update(root * 2 + 1, b, e, val);
	pushup(root);
}
void pushdown(int root)
{
	if (sa[root].visit != -1)
	{
		sa[root * 2].visit = sa[root].visit;
		sa[root * 2 + 1].visit = sa[root].visit;
		if (sa[root].visit == 0)
		{
			sa[root * 2].max = (sa[root].mid - sa[root].l + 1);
			sa[root * 2].lx = (sa[root].mid - sa[root].l + 1);
			sa[root * 2].rx = (sa[root].mid - sa[root].l + 1);
			sa[root * 2 + 1].max = (sa[root].r - sa[root].mid);
			sa[root * 2 + 1].lx = (sa[root].r - sa[root].mid);
			sa[root * 2 + 1].rx = (sa[root].r - sa[root].mid);
		}
		else
		{
			sa[root * 2].max = sa[root * 2].lx = sa[root * 2].rx = 0;
			sa[root * 2 + 1].max = sa[root * 2 + 1].lx = sa[root * 2 + 1].rx = 0;
		}
		sa[root].visit = -1;
	}
}
int query(int root, int num)
{
	if (sa[root].l == sa[root].r)
		return 1;
	pushdown(root);
	if (sa[root * 2].max >= num)
		return query(root * 2, num);
	if (sa[root * 2].rx + sa[root * 2 + 1].lx >= num)
		return (sa[root].mid - sa[root * 2].rx + 1);
	return query(root * 2 + 1, num);
}
