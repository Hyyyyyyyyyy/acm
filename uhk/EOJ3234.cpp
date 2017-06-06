#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 100;
typedef long long ll;
ll res;
ll ar[maxn], temp[maxn];
void Merge(int l, int mid, int r)
{
	int i, j, k, cnt;
	for (i = l; i <= r; i++)
		temp[i] = ar[i];
	cnt = l;
	for (i = l, j = mid + 1; i <= mid || j <= r;)
	{
		if (i > mid)
		{
			ar[cnt++] = temp[j++];
		}
		else if (j > r)
		{
			ar[cnt++] = temp[i++];
		}
		else
		{
			if (temp[i] <= temp[j])
			{
				ar[cnt++] = temp[i++];
			}
			else
			{
				ar[cnt++] = temp[j++];
				res += mid - i + 1;
			}
		}
	}
}
void mergesort(int l, int r)
{
	if (r <= l)
		return;
	int mid = (l + r) / 2;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	Merge(l, mid, r);
}

int main()
{
	int i, j, k, u, n, m, a, b;
	//freopen("IN.txt", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &ar[i]);
		}
		res = 0;
		mergesort(1, n);
		printf("%lld\n", res);
	}
	return 0;
}
