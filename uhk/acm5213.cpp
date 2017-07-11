#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 30000 + 100;
struct Node
{
	int l;
	int r;
	int block_id;
	int id;
	int sta;
};
Node Q[maxn * 5];
int ar[maxn * 4], res[maxn * 4], num[maxn * 4];
int block_len, N, M, K;
bool comp(Node& a, Node& b)
{
	if (a.block_id != b.block_id)
		return a.block_id < b.block_id;
	return a.r < b.r;
}
int add(int x)
{
	int t = 0;
	if (K > ar[x] && K - ar[x] <= N)
		t = num[K - ar[x]];
	num[ar[x]]++;
	return t;
}
int del(int x)
{
	int t = 0;
	num[ar[x]]--;
	if (K > ar[x] && K - ar[x] <= N)
		t = -num[K - ar[x]];
	return t;
}
int main()
{
	int i, j, k, u, n, m, a, b, c, d;
	while (scanf("%d", &N) != EOF)
	{
		scanf("%d", &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		block_len = (int)sqrt(N);
		scanf("%d", &M);
		int cnt = 1;
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			Q[cnt].l = a, Q[cnt].r = d, Q[cnt].block_id = Q[cnt].l / block_len, Q[cnt].sta = 1, Q[cnt++].id = i;
			Q[cnt].l = a, Q[cnt].r = c - 1, Q[cnt].block_id = Q[cnt].l / block_len, Q[cnt].sta = -1, Q[cnt++].id = i;
			Q[cnt].l = b + 1, Q[cnt].r = d, Q[cnt].block_id = Q[cnt].l / block_len, Q[cnt].sta = -1, Q[cnt++].id = i;
			Q[cnt].l = b + 1, Q[cnt].r = c - 1, Q[cnt].block_id = Q[cnt].l / block_len, Q[cnt].sta = 1, Q[cnt++].id = i;
		}
		int ans = 0;
		int l = 1;
		int r = 0;
		memset(res, 0, sizeof(res));
		memset(num, 0, sizeof(num));
		sort(Q + 1, Q + 1 + M * 4, comp);
		for (i = 1; i < cnt; i++)
		{
			while (l < Q[i].l)
				ans += del(l++);
			while (l > Q[i].l)
				ans += add(--l);
			while (r < Q[i].r)
				ans += add(++r);
			while (r > Q[i].r)
				ans += del(r--);
			res[Q[i].id] += ans * Q[i].sta;
		}
		for (i = 1; i <= M; i++)
			printf("%d\n", res[i]);
	}
	return 0;
}