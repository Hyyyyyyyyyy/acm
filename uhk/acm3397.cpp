#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100000 + 10;
struct Node
{
	int l;
	int r;
	int mid;
	int visit;
	int XO;		//异或标记
	int num;
	int len;
	int lx;
	int rx;
	int num0;
	int len0;
	int lx0;
	int rx0;
};
Node ar[maxn * 6];
int sa[maxn];
int N, M;
void pushup(int root)		//1，0节点分开写
{
	ar[root].num = ar[root * 2].num + ar[root * 2 + 1].num;
	ar[root].lx = ar[root * 2].lx + ((ar[root * 2].lx == (ar[root].mid - ar[root].l + 1)) ? ar[root * 2 + 1].lx : 0);
	ar[root].rx = ar[root * 2 + 1].rx + ((ar[root * 2 + 1].rx == (ar[root].r - ar[root].mid)) ? ar[root * 2].rx : 0);
	ar[root].len = max(max(ar[root * 2].len, ar[root * 2 + 1].len), ar[root * 2].rx + ar[root * 2 + 1].lx);

	ar[root].num0 = ar[root * 2].num0 + ar[root * 2 + 1].num0;
	ar[root].lx0 = ar[root * 2].lx0 + ((ar[root * 2].lx0 == (ar[root].mid - ar[root].l + 1)) ? ar[root * 2 + 1].lx0 : 0);
	ar[root].rx0 = ar[root * 2 + 1].rx0 + ((ar[root * 2 + 1].rx0 == (ar[root].r - ar[root].mid)) ? ar[root * 2].rx0 : 0);
	ar[root].len0 = max(max(ar[root * 2].len0, ar[root * 2 + 1].len0), ar[root * 2].rx0 + ar[root * 2 + 1].lx0);
}
void pushdown(int root)		//覆盖标记和异或标记分开，互不干扰
{
	if (ar[root].visit != -1)	
	{
		ar[root * 2].visit = ar[root * 2 + 1].visit = ar[root].visit;
		ar[root * 2].XO = ar[root * 2 + 1].XO = 0;
		if (ar[root].visit == 0)	
		{
			ar[root * 2].num = ar[root * 2 + 1].num = 0;
			ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = 0;
			ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = 0;

			ar[root * 2].num0 = ar[root].mid - ar[root].l + 1;
			ar[root * 2 + 1].num0 = ar[root].r - ar[root].mid;
			ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = ar[root].mid - ar[root].l + 1;
			ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = ar[root].r - ar[root].mid;
		}
		else if (ar[root].visit == 1)
		{
			ar[root * 2].num = ar[root].mid - ar[root].l + 1;
			ar[root * 2 + 1].num = ar[root].r - ar[root].mid;
			ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = ar[root].mid - ar[root].l + 1;
			ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = ar[root].r - ar[root].mid;

			ar[root * 2].num0 = ar[root * 2 + 1].num0 = 0;
			ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = 0;
			ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = 0;
		}
		ar[root].visit = -1;
	}
	if (ar[root].XO)
	{
		if (ar[root * 2].visit != -1)		//如果左结点被覆盖过，置换覆盖标记，再进行覆盖
		{
			ar[root * 2].visit ^= 1;
			if (ar[root * 2].visit)
			{
				ar[root * 2].num = ar[root].mid - ar[root].l + 1;
				ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = ar[root].mid - ar[root].l + 1;
				ar[root * 2].num0 = 0;
				ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = 0;
			}
			else
			{
				ar[root * 2].num = 0;
				ar[root * 2].lx = ar[root * 2].rx = ar[root * 2].len = 0;
				ar[root * 2].num0 = ar[root].mid - ar[root].l + 1;
				ar[root * 2].lx0 = ar[root * 2].rx0 = ar[root * 2].len0 = ar[root].mid - ar[root].l + 1;
			}
		}
		else		//否则，直接互换0，1的信息
		{
			ar[root * 2].XO ^= 1;
			swap(ar[root * 2].num, ar[root * 2].num0);
			swap(ar[root * 2].len, ar[root * 2].len0);
			swap(ar[root * 2].lx, ar[root * 2].lx0);
			swap(ar[root * 2].rx, ar[root * 2].rx0);
		}
		if (ar[root * 2 + 1].visit != -1)		//右结点同左结点
		{
			ar[root * 2 + 1].visit ^= 1;
			if (ar[root * 2 + 1].visit)
			{
				ar[root * 2 + 1].num = ar[root].r - ar[root].mid;
				ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = ar[root].r - ar[root].mid;
				ar[root * 2 + 1].num0 = 0;
				ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = 0;
			}
			else
			{
				ar[root * 2 + 1].num = 0;
				ar[root * 2 + 1].lx = ar[root * 2 + 1].rx = ar[root * 2 + 1].len = 0;
				ar[root * 2 + 1].num0 = ar[root].r - ar[root].mid;
				ar[root * 2 + 1].lx0 = ar[root * 2 + 1].rx0 = ar[root * 2 + 1].len0 = ar[root].r - ar[root].mid;
			}
		}
		else
		{
			ar[root * 2 + 1].XO ^= 1;
			swap(ar[root * 2 + 1].num, ar[root * 2 + 1].num0);
			swap(ar[root * 2 + 1].len, ar[root * 2 + 1].len0);
			swap(ar[root * 2 + 1].lx, ar[root * 2 + 1].lx0);
			swap(ar[root * 2 + 1].rx, ar[root * 2 + 1].rx0);
		}
		//ar[root * 2].XO ^= 1;
		//ar[root * 2 + 1].XO ^= 1;

		//swap(ar[root * 2].num, ar[root * 2].num0);
		//swap(ar[root * 2].len, ar[root * 2].len0);
		//swap(ar[root * 2].lx, ar[root * 2].lx0);
		//swap(ar[root * 2].rx, ar[root * 2].rx0);

		//swap(ar[root * 2 + 1].num, ar[root * 2 + 1].num0);
		//swap(ar[root * 2 + 1].len, ar[root * 2 + 1].len0);
		//swap(ar[root * 2 + 1].lx, ar[root * 2 + 1].lx0);
		//swap(ar[root * 2 + 1].rx, ar[root * 2 + 1].rx0);

		ar[root].XO = 0;
	}
}
void build(int root, int begin, int end)
{
	ar[root].l = begin;
	ar[root].r = end;
	ar[root].mid = (begin + end) / 2;
	ar[root].visit = -1;
	ar[root].XO = 0;
	if (begin == end)
	{
		ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = sa[ar[root].l];
		ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = sa[ar[root].l] ^ 1;
		return;
	}
	build(root * 2, ar[root].l, ar[root].mid);
	build(root * 2 + 1, ar[root].mid + 1, ar[root].r);
	pushup(root);
}
void update(int root, int b, int e, int val)
{
	if (ar[root].l > e || ar[root].r < b)
		return;
	if (ar[root].l >= b && ar[root].r <= e)
	{
		if (val == 0)
		{
			ar[root].visit = val;
			ar[root].XO = 0;
			ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = 0;

			ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = ar[root].r - ar[root].l + 1;
		}
		else if (val == 1)
		{
			ar[root].visit = val;
			ar[root].XO = 0;
			ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;

			ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = 0;
		}
		else
		{
			if (ar[root].visit != -1)
			{
				ar[root].visit ^= 1;
				if (ar[root].visit == 0)
				{
					ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = 0;
					ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = ar[root].r - ar[root].l + 1;
				}
				else
				{
					ar[root].num = ar[root].lx = ar[root].rx = ar[root].len = ar[root].r - ar[root].l + 1;
					ar[root].num0 = ar[root].lx0 = ar[root].rx0 = ar[root].len0 = 0;
				}
			}
			else
			{
				ar[root].XO ^= 1;
				swap(ar[root].num, ar[root].num0);
				swap(ar[root].len, ar[root].len0);
				swap(ar[root].lx, ar[root].lx0);
				swap(ar[root].rx, ar[root].rx0);
			}
		}
		return;
	}
	pushdown(root);
	if (b <= ar[root].mid)
		update(root * 2, b, e, val);
	if (e > ar[root].mid)
		update(root * 2 + 1, b, e, val);
	pushup(root);
}
int query_num(int root, int b, int e)
{
	if (ar[root].l > e || ar[root].r < b)
		return 0;
	if (ar[root].l >= b && ar[root].r <= e)
	{
		return ar[root].num;
	}
	pushdown(root);
	int res = 0;
	if (b <= ar[root].mid)
		res += query_num(root * 2, b, e);
	if (e > ar[root].mid)
		res += query_num(root * 2 + 1, b, e);
	return res;
}
int query_len(int root, int b, int e)
{
	if (ar[root].l > e || ar[root].r < b)
		return 0;
	if (ar[root].l >= b && ar[root].r <= e)
	{
		return ar[root].len;
	}
	pushdown(root);
	int res = 0;
	res = max(query_len(root * 2, b, e), query_len(root * 2 + 1, b, e));
	res = max(res, (min(ar[root * 2].r - b + 1, ar[root * 2].rx) + min(e - ar[root * 2 + 1].l + 1, ar[root * 2 + 1].lx)));
	return res;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	//freopen("IN.txt", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &sa[i]);
			}
			build(1, 1, N);
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d %d", &a, &b, &c);
				b++;
				c++;
				if (a == 0)
				{
					update(1, b, c, 0);
				}
				else if (a == 1)
				{
					update(1, b, c, 1);
				}
				else if (a == 2)
				{
					update(1, b, c, 2);
				}
				else if (a == 3)
				{
					printf("%d\n", query_num(1, b, c));
				}
				else
				{
					printf("%d\n", query_len(1, b, c));
				}
			}
		}
	}
	return 0;
}