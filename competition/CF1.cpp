#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int i, j, k, n, m, a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int l = 0;
		int r = 100000;
		int mid;
		while (r >= l)
		{
			mid = (l + r) / 2;
			ll x = (ll)mid*mid;
			if (x <= a)
				l = mid + 1;
			else
				r = mid - 1;
		}
		int posa = r;
		l = 0;
		r = 100000;
		while (r >= l)
		{
			mid = (l + r) / 2;
			ll x = (ll)mid*mid + (ll)mid;
			if (x <= b)
				l = mid + 1;
			else
				r = mid - 1;
		}
		int posb = r;
		//printf("%d %d\n", posa, posb);
		if (posa > posb)
			printf("Valera\n");
		else
			printf("Vladik\n");
	}
	return 0;
}
