#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int i, j, k, u, n, m, a, b, doudou;
	while (scanf("%d", &n) != EOF)
	{
        for(m = 1; m <= n; m++)
		{
            scanf("%d %d", &a, &b);
            if (b >= a)
            {
                printf("Grass\n");
            }
            else if (a % (b + 1) == 0)
            {
                printf("Rabbit\n");
            }
            else
            {
                printf("Grass\n");
            }
        }
	}
	return 0;
}
