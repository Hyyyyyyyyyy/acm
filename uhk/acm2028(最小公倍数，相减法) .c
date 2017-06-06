#include <stdio.h>
long long int F(long long int r, long long int t);
int main()
{
	long long int a, b;
	int n, m;

	while (scanf("%d", &n) != EOF)
	{
		scanf("%lld", &a);
		for (m = 2; m <= n; m++)
		{
			scanf("%lld", &b);
			a = (a * b) / F(a, b);
		}
		printf("%lld\n", a);
	}
	return 0;
}

long long int F(long long int r, long long int t)
{
	if (r < t)
	{
		r = r + t;
		t = r - t;
		r = r - t;
	}
	if ((r - t) == t)
		return t;
	else
		return F(r - t, t);
}
