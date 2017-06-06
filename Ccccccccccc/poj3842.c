#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int i, j, k, n;
	double m, ar[10000], sa[10000];
	while (scanf("%d", &k) != EOF && k)
	{
		scanf("%lf", &m);
		ar[k] = 0;
		sa[k] = 0;
		for (i = k - 1; i >= 0; i--)
		{
			ar[i] = ar[i + 1] + 1.0 / m;
			sa[i] = 2.0 / m * ar[i] + 1.0 / m - 2.0 * ar[i] + 2.0 * ar[i+1] + sa[i+1];
		}
		printf("%.3lf %.3lf\n", ar[0], sa[0]);
	}
	return 0;
}
