#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
const int MAX = 10010;
using namespace std;

int main()
{
	char ar[MAX], sa[MAX];
	int i, j, k, u, n, m, L, cnt;
	char temp, t;
	while (scanf("%s", ar) != EOF)
	{
		L = strlen(ar);
		temp = ar[0];
		n = 0;
		cnt = 0;
		for (i = 0; i < L; i++)
		{
			if (temp == ar[i])
			{
				n++;
				continue;
			}
			printf("%d%c", n, temp);
			temp = ar[i];
			n = 1;
		}
        printf("%d%c\n", n, temp);
	}
	return 0;
}