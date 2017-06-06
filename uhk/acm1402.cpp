#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
ull F(ull a, ull b, ull c)
{
	int i;
	ull S = 1;
	while (b)
	{
		if (b & 1)
		{
			S = (S * a) % c;
			b--;
		}
		a = (a * a) % c;
		b >>= 1;
	}
	return S;
}
int main()
{
	ull i, j, k, u, n, m, a, b, c;
	while (scanf("%llu", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%llu %llu %llu", &a, &b, &c);
			printf("%llu\n", F(a, b, c) % c);
		}
	}
	return 0;
}
