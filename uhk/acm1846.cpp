#include <cstdio>
using namespace std;
int main()
{
	int i, j, k, a, b, n, m;
	scanf("%d", &n);
	for (m = 1; m <= n; m++)
	{
		scanf("%d %d", &a, &b);
		if (a % (b + 1) == 0)
		{
			printf("second\n");
		}
		else
		{
			printf("first\n");
		}
	}
	return 0;
}
