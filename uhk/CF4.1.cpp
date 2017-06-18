#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 50;
char ar[maxn];
int main()
{
	int i, j, k, u, n, m;
	int cnt = 0;
	while (scanf("%s", ar) != EOF)
	{
		if (ar[0] == ar[4] && ar[1] == ar[3])
		{
			printf("0\n");
			continue;
		}
		cnt = 0;
		while (1)
		{
			ar[4]++;
			if (ar[4] > '9')
			{
				ar[3]++;
				ar[4] = '0';
			}
			if (ar[3] >= '6')
			{
				ar[1]++;
				ar[3] = '0';
			}
			if (ar[0] == '2')
			{
				if (ar[1] >= '4')
				{
					ar[1] = '0';
					ar[0]++;
				}
				if (ar[0] > '2')
				{
					ar[0] = '0';
				}
			}
			else
			{
				if (ar[1] > '9')
				{
					ar[1] = '0';
					ar[0]++;
				}
			}
			if (ar[0] != ar[4] || ar[1] != ar[3])
				cnt++;
			else
				break;
		}
		printf("%d\n", cnt + 1);
	}
	return 0;
}