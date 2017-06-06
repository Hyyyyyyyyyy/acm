#include <stdio.h>
long long int F(long long int r, long long int t);
int main()
{
	int n, m, i;
	long long int a, b;

	while (scanf("%d", &n) != EOF)
	{
		scanf("%lld", &a);
		for (i = 2; i <= n; i++)
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
	if ((r%t) == 0)
		return t;
	else
		return F(t, r%t);
}