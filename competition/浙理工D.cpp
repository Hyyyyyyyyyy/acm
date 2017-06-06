#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int main()
{
	long long i, j, k, u, n, m, a, b, c, p, doudou, q, r, t, s;
	while (scanf("%lld %lld %lld %lld %lld", &n, &k, &a, &b, &c) != EOF)
	{
		doudou = 0;
		p = a - c;
		q = b - c;
		r = n - c*k;
		t = n / a;
		t += n % a;
		s = n / b;
		s += n % b;
		for (i = 0; i <= t; i++)
		{
			for (j = 0; j <= s; j++)
			{
				if (p*i + q*j == r && k -i -j >= 0)
				{
					doudou = 1;
					break;
				}
			}
			if (doudou)
				break;
		}
		//printf("%d %d %d\n", i, j, k - i - j);
		if (doudou)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
