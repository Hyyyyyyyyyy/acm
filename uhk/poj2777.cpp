#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
typedef long long ll;
struct node
{
	int l;
	int r;
	int mid;
	ll sta;
	int visit;
};
node sa[100000 * 4];
int ar[100000 * 4];
int N, M, n;
void build(int root, int begin, int end);
void update(int root, int b, int e, int val);
void pushup(int root);
void pushdown(int root);
ll query(int root, int b, int e);
int main()
{
	int i, j, k, u, m, a, b, c;
	char s[5];
	while (scanf("%d %d %d", &N, &n, &M) != EOF)
	{
		build(1, 1, N);
		for (u = 1; u <= M; u++)
		{
			scanf("%s%d%d", s, &a, &b);
			int temp;
			if (a > b)
			{
				temp = a;
				a = b;
				b = temp;
			}
			if (strcmp(s, "C") == 0)
			{
				scanf("%d", &c);
				update(1, a, b, c);
			}
			else
			{
				ll res = query(1, a, b);
				int num = 0;
				while (res)
				{
					if (res & 1)
						num++;
					res >>= 1;
				}
				printf("%d\n", num);
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
	sa[root].visit = 0;
	if (begin == end)
	{
		sa[root].sta = 1;
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
	sa[root].sta = sa[root * 2].sta | sa[root * 2 + 1].sta;
}
void update(int root, int b, int e, int val)
{
	if (sa[root].l > e || sa[root].r < b)
		return;
	if (sa[root].l >= b && sa[root].r <= e)
	{
		sa[root].sta = (ll)1 << (val-1);
		sa[root].visit += val;
		return;
	}
	pushdown(root);
	update(root * 2, b, e, val);
	update(root * 2 + 1, b, e, val);
	pushup(root);
}
void pushdown(int root)
{
	if (sa[root].visit)
	{
		sa[root * 2].visit += sa[root].visit;
		sa[root * 2 + 1].visit += sa[root].visit;
		sa[root * 2].sta = sa[root].sta;
		sa[root * 2 + 1].sta = sa[root].sta;
		sa[root].visit = 0;
	}
}
ll query(int root, int b, int e)
{
	if (sa[root].l > e || sa[root].r < b)
		return 0;
	if (sa[root].l >= b && sa[root].r <= e)
		return sa[root].sta;
	pushdown(root);
	return query(root * 2, b, e) | query(root * 2 + 1, b, e);
}

