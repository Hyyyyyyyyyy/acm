#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int i, j, k, n, m, t, a;
	while (scanf("%d", &n) != EOF && n)
	{
		t = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &a);
			t ^= a;
		}
		if (t == 0)
		{
			printf("Grass Win!\n");
		}
		else
		{
			printf("Rabbit Win!\n");
		}
	}
	return 0;
}