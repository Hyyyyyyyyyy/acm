#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int ar[50000 * 4];
int sa[50000 * 4][55];
int visit[50000 * 4];
int id[11][11];
int cur;
void build(int root, int begin, int end);
void update(int root, int begin, int end, int b, int e, int val);
void pushdown(int root);
int query(int root, int begin, int end, int index);
int main()
{
	int cnt = 0;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < i; j++)
		{
			id[i][j] = cnt++;
		}
	int i, j, k, u, n, m, a, b, c, d, e;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
		}
		build(1, 1, n);
		scanf("%d", &k);
		for (u = 1; u <= k; u++)
		{
			scanf("%d", &a);
			if (a == 2)
			{
				scanf("%d", &b);
				printf("%d\n", query(1, 1, n, b));
			}
			else
			{
				scanf("%d %d %d %d", &b, &c, &d, &e);
				cur = id[d][b % d];
				update(1, 1, n, b, c, e);
			}
		}
	}
	return 0;
}
void build(int root, int begin, int end)
{
	visit[root] = 0;
	for (int i = 0; i < 55; i++)
		sa[root][i] = 0;
	if (begin == end)
		return;
	else
	{
		build(root * 2, begin, (begin + end) / 2);
		build(root * 2 + 1, (begin + end) / 2 + 1, end);
	}
}
void update(int root, int begin, int end, int b, int e, int val)
{
	if (begin > e || end < b)
		return;
	if (begin >= b && end <= e)
	{
		sa[root][cur] += val;
		visit[root] = 1;
		return;
	}
	pushdown(root);
	int mid = (begin + end) / 2;
	update(root * 2, begin, mid, b, e, val);
	update(root * 2 + 1, mid + 1, end, b, e, val);

}
void pushdown(int root)
{
	if (visit[root])
	{
		for (int i = 0; i < 55; i++)
		{
			sa[root * 2][i] += sa[root][i];
			sa[root * 2 + 1][i] += sa[root][i];
			sa[root][i] = 0;
		}
		visit[root * 2 + 1] = visit[root];
        visit[root * 2] = visit[root];
		visit[root] = 0;
	}
}
int query(int root, int begin, int end, int index)
{
	if (begin == end)
	{
		int res = ar[begin];
		for (int i = 1; i <= 10; i++)
			res += sa[root][id[i][index % i]];
		return res;
	}
	pushdown(root);
	int mid = (begin + end) / 2;
	if (index <= mid)
		return query(root * 2, begin, mid, index);
	else
		return query(root * 2 + 1, mid + 1, end, index);
}
