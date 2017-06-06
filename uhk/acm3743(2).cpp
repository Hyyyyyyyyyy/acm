#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000000 + 100;
typedef long long ll;
struct Node
{
	int index;
	int val;
};
Node ar[maxn];
int C[maxn];
int b[maxn];
bool comp(const Node& a, const Node& b)
{
	return a.val < b.val;
}
int sum(int x)
{
	int s = 0;
	while (x)
	{
		s += C[x];
		x -= x & (-x);
	}
	return s;
}
void update(int x, int val, int n)
{
	while (x <= n)
	{
		C[x] += val;
		x += x & (-x);
	}
}
int main()
{
	int i, j, k, u, n, m, a;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i].val);
			ar[i].index = i;
		}
		sort(ar + 1, ar + 1 + n, comp);
		for (i = 1; i <= n; i++)
		{
			b[ar[i].index] = i;
		}
		memset(C, 0, sizeof(C));
		ll res = 0;
		for (i = 1; i <= n; i++)
		{
			res += i - sum(b[i]) - 1;
			update(b[i], 1, n);
		}
		printf("%lld\n", res);
	}
	return 0;
}