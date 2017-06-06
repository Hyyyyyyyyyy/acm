#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int maxn = 200000 + 10;
int N, H, W;
struct Node
{
	int l;
	int r;
	int mid;
	int w;
};
Node ar[maxn * 4];
void build(int root, int begin, int end)
{
	ar[root].l = begin;
	ar[root].r = end;
	ar[root].mid = (begin + end) / 2;
	ar[root].w = W;
	if (begin == end)
	{
		return;
	}
	build(root * 2, ar[root].l, ar[root].mid);
	build(root * 2 + 1, ar[root].mid + 1, ar[root].r);
}
int update(int root, int begin, int end, int val)
{
	if (ar[root].w < val)
		return -1;
	if (begin == end)
	{
		ar[root].w -= val;
		return begin;
	}
	int res;
	if (ar[root * 2].w >= val)
		res = update(root * 2, ar[root].l, ar[root].mid, val);
	else
		res = update(root * 2 + 1, ar[root].mid + 1, ar[root].r, val);
	ar[root].w = max(ar[root * 2].w, ar[root * 2 + 1].w);
	return res;
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d %d", &H, &W, &N) != EOF)
	{
		if (H > N)
			H = N;
		build(1, 1, H);
		for (m = 1; m <= N; m++)
		{
			scanf("%d", &a);
			printf("%d\n", update(1, 1, H, a));
		}
	}
	return 0;
}