#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int i, j, k, u, n, m, a, b, doudou;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (m >= n)
		{
			doudou = 0;
			while (m >= n)
			{
				if (doudou)
					putchar(' ');
				doudou = 1;
				printf("%d", n++);
			}
			putchar('\n');
		}
		else if (n % (m + 1) == 0)
		{
			printf("none\n");
		}
		else
		{
			printf("%d\n", n % (m + 1));
		}
	}
	return 0;
}
