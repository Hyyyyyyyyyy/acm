#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int gcd(int x, int y)
{
	int t;
	while (y)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return  x;
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			if (b % a == 0)
				printf("%d\n", b / a);
			else
			{
				printf("%d\n", a / gcd(a, b)*b / a);
			}
		}
	}
	return 0;
}