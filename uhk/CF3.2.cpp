#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000000 + 100;
typedef __int64 ll;
ll ar[maxn], sa[maxn];
ll C(ll a, ll b)
{
	ll i, j, k;
	ll A = 1;
	ll D = 1;
	ll c = a - b;
	for (i = a; i > c; i--)
		A *= i;
	for (i = 1; i <= b; i++)
		D *= i;
	return A/D;
}
int main()
{
	int i, j, k, u, n, m;
	ll flag1, flag2, flag3;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%I64d", &ar[i]);
			sa[i] = ar[i];
		}
		sort(ar + 1, ar + 1 + n);
		flag1 = flag2 = flag3 = 0;
		for (i = 1; i <= n; i++)
		{
			if (sa[i] == ar[1])
				flag1++;
			if (sa[i] == ar[2])
				flag2++;
			if (sa[i] == ar[3])
				flag3++;
		}
		if (ar[1] == ar[2] && ar[2] == ar[3])
		{
			printf("%I64d\n", C(flag1, 3));
			continue;
		}
		if (ar[1] == ar[2] && ar[1] != ar[3])
		{
			printf("%I64d\n", flag3);
			continue;
		}
		if (ar[1] != ar[2] && ar[2] == ar[3])
		{
			printf("%I64d\n", flag1);
			continue;
		}
		if (ar[1] == ar[3] && ar[2] != ar[1])
		{
			printf("%I64d\n", flag2);
			continue;
		}
		if (ar[1] != ar[2] && ar[1] != ar[3] && ar[2] != ar[3])
		{
			printf("%I64d\n", flag3);
		}
	}
	return 0;
}
