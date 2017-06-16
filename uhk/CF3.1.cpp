#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int bx, by, ex, ey, X, Y;
int main()
{
	int i, j, k, u, n, m, a, b, c, d;
	while (scanf("%d %d %d %d", &bx, &by, &ex, &ey) != EOF)
	{
		scanf("%d %d", &X, &Y);
		if (abs(bx - ex) % X != 0 || abs(by - ey) % Y != 0)
		{
			printf("NO\n");
			continue;
		}
		int t1 = abs(bx - ex) / X;
		int t2 = abs(by - ey) / Y;
		if (abs(t1 - t2) % 2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}