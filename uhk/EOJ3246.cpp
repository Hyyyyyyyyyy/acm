#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int maxn = 100000 + 10;
struct Node
{
	int x;
	int l;
	int r;
	int index;
};
Node ar[maxn * 4];
bool comp(const Node&a, const Node& b)
{
	return a.x < b.x;
}
int L[maxn], R[maxn];        //表示i能影响到的最左、右远点
int rig[2][maxn * 4];         //表示root区间下的最左、右远点， lef只有0有用， rig只有1有用；
int lef[2][maxn * 4];
int res[maxn];
int MAX;
void update(int root, int begin, int end, int index, int val, int sta)
{
	if (begin == end && begin == index)
	{
		lef[sta][root] = rig[sta][root] = val;
		return;
	}
	if (begin > index || end < index)
		return;
	int mid = (begin + end) / 2;
	if(index <= mid)
		update(root * 2, begin, mid, index, val, sta);
	else
		update(root * 2 + 1, mid + 1, end, index, val, sta);
	lef[sta][root] = min(lef[sta][root * 2], lef[sta][root * 2 + 1]);
	rig[sta][root] = max(rig[sta][root * 2], rig[sta][root * 2 + 1]);
}
void query_Min(int root, int begin, int end, int b, int e, int sta)
{
	if (b <= begin && end <= e)
	{
		MAX = min(MAX, lef[sta][root]);
		return;
	}
	if (begin > e || end < b)
		return;
	int mid = (begin + end) / 2;
	query_Min(root * 2, begin, mid, b, e, sta);
	query_Min(root * 2 + 1, mid + 1, end, b, e, sta);
}
void query_Max(int root, int begin, int end, int b, int e, int sta)
{
	if (b <= begin && end <= e)
	{
		MAX = max(MAX, rig[sta][root]);
		return;
	}
	if (begin > e || end < b)
		return;
	int mid = (begin + end) / 2;
	query_Max(root * 2, begin, mid, b, e, sta);
	query_Max(root * 2 + 1, mid + 1, end, b, e, sta);
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			ar[m].x = a;
			ar[m].l = a - b;
			ar[m].r = a + b;
			ar[m].index = m;
		}
		sort(ar + 1, ar + 1 + n, comp);
		for (i = 1; i <= n; i++)
		{
            int pos;
			int l = 1;
			int r = i;
			int mid;
			while (r >= l)
			{
                mid = (l + r) / 2;
				if (ar[i].l > ar[mid].x)
					l = mid + 1;
				else if (ar[i].l <= ar[mid].x)
					r = mid - 1;
				else
					break;
			}
			L[i] = l;

			l = i;
			r = n;
			mid = (l + r) / 2;
			while (r >= l)
			{
                mid = (l + r) / 2;
				if (ar[i].r >= ar[mid].x)
					l = mid + 1;
				else if (ar[i].r < ar[mid].x)
					r = mid - 1;
				else
					break;
			}
			R[i] = r;
		}
		for (i = 1; i <= n; i++)
		{
			update(1, 1, n, i, L[i], 0);
			update(1, 1, n, i, R[i], 1);
		}
		int doudou = 1;
		while (doudou)
		{
			doudou = 0;
			for (i = 1; i <= n; i++)
			{
				MAX = INF;
				query_Min(1, 1, n, L[i], i, 0);
				if (MAX != L[i])
				{
					L[i] = MAX;
					update(1, 1, n, i, L[i], 0);
					doudou = 1;
				}
			}
			for (i = n; i >= 1; i--)
			{
				MAX = -INF;
				query_Max(1, 1, n, i, R[i], 1);
				if (MAX != R[i])
				{
					R[i] = MAX;
					update(1, 1, n, i, R[i], 1);
					doudou = 1;
				}
			}
			for (i = n; i >= 1; i--)
			{
				MAX = INF;
				query_Min(1, 1, n, i, R[i], 0);
				if (MAX != L[i])
				{
					L[i] = MAX;
					update(1, 1, n, i, L[i], 0);
					doudou = 1;
				}
			}
			for (i = 1; i <= n; i++)
			{
				MAX = -INF;
				query_Max(1, 1, n, L[i], i, 1);
				if (MAX != R[i])
				{
					R[i] = MAX;
					update(1, 1, n, i, R[i], 1);
					doudou = 1;
				}
			}
		}
		for (i = 1; i <= n; i++)
		{
			res[ar[i].index] = R[i] - L[i] + 1;
		}
		for (i = 1; i <= n; i++)
		{
			if (i != 1)
				printf(" ");
			printf("%d", res[i]);
		}
		putchar('\n');
	}
	return 0;
}