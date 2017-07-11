#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100000 + 100;
int ar[maxn], num[maxn], res[maxn];
struct Node
{
	int id;
	int block_id;
	int l;
	int r;
	int ans;
};
Node Q[maxn];
int block_len;
inline bool comp(Node& a, Node& b)
{
	if (a.block_id != b.block_id)
		return a.block_id < b.block_id;
	else
		return a.r < b.r;
}
inline int del(int x)
{
	int t = ar[x];
	num[t] = 0;
	if (num[t + 1] && num[t - 1])
		return 1;
	if (!num[t + 1] && !num[t - 1])
		return -1;
	return 0;
}
inline int add(int x)
{
	int t = ar[x];
	num[t] = 1;
	if (num[t + 1] && num[t - 1])
		return -1;
	if (!num[t + 1] && !num[t - 1])
		return 1;
	return 0;
}
int main()
{
	int i, j, k, u, n, m, a, b, N, M;
	scanf("%d", &n);
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			block_len = (int)sqrt(1.0*N);
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d", &Q[i].l, &Q[i].r);
				Q[i].block_id = Q[i].l / block_len;
				Q[i].id = i;
			}
			memset(num, 0, sizeof(num));
			sort(Q + 1, Q + 1 + M, comp);
			int l = 1;
			int r = 0;
			int ans = 0;
			for (i = 1; i <= M; i++)
			{
				if (r < Q[i].l || l > Q[i].r)
				{
					while (l <= r)
					{
						num[ar[l]] = 0;
						l++;
					}
					ans = 0;
					l = Q[i].l;
					r = Q[i].l - 1;
					while (r < Q[i].r)
					{
						ans += add(++r);
					}
					res[Q[i].id] = ans;
					continue;
				}
				while (l < Q[i].l)
					ans += del(l++);
				while (l > Q[i].l)
					ans += add(--l);
				while (r < Q[i].r)
					ans += add(++r);
				while (r > Q[i].r)
					ans += del(r--);

				res[Q[i].id] = ans;
			}
			for (i = 1; i <= M; i++)
			{
				printf("%d\n", res[i]);
			}
		}
	}
	return 0;
}