#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int maxn = 50000 + 100;
struct  Node
{
	int l;
	int r;
	int mid;
	int start;      //该节点属于的Memory block的左端
	int end;        //该节点属于的Memory block的右端
	int lx;
	int rx;
	int len;
	int num;        //该节点下的memory block的个数
	int visit;      //1表示有memory block，2表示没memory block
	int num_visit;		//对memory block的个数有无操作的标记
};
Node ar[maxn * 4];
int N, M;
void pushup(int root);
void pushdown(int root);
void update_new(int root, int begin, int end);
void update_free(int root, int begin, int end);
void update_num(int root, int x, int val);
int query_new(int root, int val);
int query_free(int root, int x);
int query_get(int root, int x);
void build(int root, int begin, int end);    //其实没啥用只执行一步，但是线段树不写build感觉别扭
int main()
{
	int i, j, k, n, u, m, a, b;
	char s[50];
	//freopen("IN.txt", "r", stdin);
	while (scanf("%d %d", &N, &M) != EOF)
	{
		build(1, 1, N);
		int cnt = 1;
		for (i = 1; i <= M; i++)
		{
			scanf("%s", s);
			if (strcmp(s, "Reset") == 0)
			{
				update_free(1, 1, N);
				printf("Reset Now\n");
			}
			else if (strcmp(s, "New") == 0)
			{
				scanf("%d", &a);
				if (ar[1].len < a)
					printf("Reject New\n");
				else
				{
					int l = query_new(1, a);
					printf("New at %d\n", l);
					update_num(1, l, 1);
					update_new(1, l, l + a - 1);
				}
			}
			else if (strcmp(s, "Free") == 0)
			{
				scanf("%d", &a);
				int t = query_free(1, a);
				if (ar[t].start == 0 || ar[t].end == 0 || t == -1)
					printf("Reject Free\n");
				else
				{
					printf("Free from %d to %d\n", ar[t].start, ar[t].end);
					update_num(1, ar[t].start, 0);
					update_free(1, ar[t].start, ar[t].end);
				}
			}
			else
			{
				scanf("%d", &a);
				if (a > ar[1].num)
					printf("Reject Get\n");
				else
				{
					int t = query_get(1, a);
					printf("Get at %d\n", ar[t].l);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
void pushup(int root)
{
	int i, j;
	ar[root].lx = ar[root * 2].lx + (ar[root * 2].lx == (ar[root].mid - ar[root].l + 1) ? ar[root * 2 + 1].lx : 0);
	ar[root].rx = ar[root * 2 + 1].rx + (ar[root * 2 + 1].rx == (ar[root].r - ar[root].mid) ? ar[root * 2].rx : 0);
	ar[root].len = max(max(ar[root * 2].len, ar[root * 2 + 1].len), ar[root * 2].rx + ar[root * 2 + 1].lx);
	ar[root].num = ar[root * 2].num + ar[root * 2 + 1].num;
}
void pushdown(int root)
{
	ar[root * 2].l = ar[root].l;
	ar[root * 2].r = ar[root].mid;
	ar[root * 2].mid = (ar[root * 2].l + ar[root * 2].r) / 2;

	ar[root * 2 + 1].r = ar[root].r;
	ar[root * 2 + 1].l = ar[root].mid + 1;
	ar[root * 2 + 1].mid = (ar[root * 2 + 1].l + ar[root * 2 + 1].r) / 2;

	if (ar[root].visit != -1)
	{
		ar[root * 2].visit = ar[root * 2 + 1].visit = ar[root].visit;

		ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = (ar[root].visit ^ 1) * (ar[root].mid - ar[root].l + 1);
		ar[root * 2].start = ar[root].start;
		ar[root * 2].end = ar[root].end;
		ar[root * 2].num = ar[root].visit;

		ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = (ar[root].visit ^ 1) * (ar[root].r - ar[root].mid);
		ar[root * 2 + 1].start = ar[root].start;
		ar[root * 2 + 1].end = ar[root].end;
		ar[root * 2 + 1].num = ar[root].visit;

		ar[root].visit = -1;
	}
	if (ar[root].num_visit)
	{
		ar[root * 2].num = ar[root * 2 + 1].num = 0;
		ar[root * 2].num_visit = ar[root * 2 + 1].num_visit = 1;
		ar[root].num_visit = 0;
	}
}
void build(int root, int begin, int end)
{
	ar[root].l = begin;
	ar[root].r = end;
	ar[root].mid = (begin + end) / 2;
	ar[root].start = 0;
	ar[root].end = 0;
	ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
	ar[root].num = 0;
	ar[root].visit = 0;
	ar[root].num_visit = 1;
	if (begin <= ar[root].l && ar[root].r <= end)
	{
		pushdown(root);
		return;
	}
}
void update_new(int root, int begin, int end)
{
	if (begin <= ar[root].l && ar[root].r <= end)
	{
		ar[root].start = begin;
		ar[root].end = end;
		ar[root].lx = ar[root].rx = ar[root].len = 0;
		ar[root].visit = 1;
		return;
	}
	pushdown(root);
	if (begin <= ar[root].mid)
		update_new(root * 2, begin, end);
	if (end > ar[root].mid)
		update_new(root * 2 + 1, begin, end);
	pushup(root);
}
void update_free(int root, int begin, int end)
{
	if (begin <= ar[root].l && ar[root].r <= end)
	{
		ar[root].start = ar[root].end = 0;
		ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
		ar[root].visit = 0;
		ar[root].num = 0;
		ar[root].num_visit = 1;
		return;
	}
	pushdown(root);
	if (begin <= ar[root].mid)
		update_free(root * 2, begin, end);
	if (end > ar[root].mid)
		update_free(root * 2 + 1, begin, end);
	pushup(root);
}
void update_num(int root, int x, int val)
{
	if (ar[root].l == ar[root].r)
	{
		ar[root].num = val;
		return;
	}
	pushdown(root);
	if (x <= ar[root].mid)
		update_num(root * 2, x, val);
	else
		update_num(root * 2 + 1, x, val);
	pushup(root);
}
int query_new(int root, int val)
{
	if (ar[root].l == ar[root].r)
	{
		return ar[root].l;
	}
	pushdown(root);
	if (ar[root * 2].len >= val)
		return query_new(root * 2, val);
	else if (ar[root * 2].rx + ar[root * 2 + 1].lx >= val)
		return (ar[root * 2].r - ar[root * 2].rx + 1);
	else
		return query_new(root * 2 + 1, val);
}
int query_free(int root, int x)
{
	if (ar[root].l == ar[root].r)
	{
		if (ar[root].l == x)
			return root;
		else
			return -1;
	}
	pushdown(root);
	if (x <= ar[root].mid)
		query_free(root * 2, x);
	else
		query_free(root * 2 + 1, x);
}
int query_get(int root, int x)
{
	if (ar[root].l == ar[root].r)
	{
		return root;
	}
	pushdown(root);
	if (x <= ar[root * 2].num)
		query_get(root * 2, x);
	else
		query_get(root * 2 + 1, x - ar[root * 2].num);
}
