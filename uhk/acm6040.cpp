#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 1e9 + 1;
const int maxn = 10000000 + 100;
unsigned n, m, A, B, C;
unsigned ar[maxn], sa[110], id[110], res[110];
unsigned x, y, z;
bool comp(int a, int b)
{
	return sa[a] > sa[b];
}
unsigned rng61()
{
	unsigned t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}
int main()
{
	int i, j, k, u, cas = 1;
	while (scanf("%u %u %u %u %u", &n, &m, &A, &B, &C) != EOF)
	{
		x = A, y = B, z = C;
		for (i = 0; i < m; i++)
		{
			scanf("%u", &sa[i]);
			id[i] = i;
		}
		for (i = 0; i < n; i++)
		{
			ar[i] = rng61();
		}
		sort(id, id + m, comp);
		int p;
		int last = n;
		for (i = 0; i < m; i++)
		{
			p = id[i];
			nth_element(ar, ar + sa[p], ar + last);
			res[p] = ar[sa[p]];
			last = sa[p];
		}
		printf("Case #%d:", cas++);
		for (i = 0; i < m; i++)
		{
			printf(" %u", res[i]);
		}
		putchar('\n');
	}
	return 0;
}