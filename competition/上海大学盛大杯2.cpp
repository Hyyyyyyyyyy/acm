#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 510;
typedef long long ll;
int ar[maxn], sum;
int main()
{
	int i, j, k, u, n, m, cnt;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		cnt = 0;
		int flag = 0;
		int doudou1 = 0;
		int doudou2 = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
			if (flag)
			{
				if (ar[i])
				{
					doudou1++;
				}
				else
				{
					doudou2++;
				}
				if (doudou1 == 2)
				{
					cnt++;
					sum = 0;
					flag = 0;
					doudou1 = 0;
					doudou2 = 0;
				}
				if (doudou2 == 2)
				{
					sum = 60;
					flag = 0;
					doudou1 = 0;
					doudou2 = 0;
				}
			}
			else
			{
				if (ar[i])
				{
					sum += 10;
				}
				else
					sum -= 5;
				if (sum >= 100)
				{
                    if(cnt < 4)
						flag = 1;
                    else
                    {
                        sum = 100;
                    }
				}
				else if (sum < 0)
				{
					sum = 0;
				}
			}
		}
		if (cnt == 0)
		{
			printf("D\n");
		}
		else if (cnt == 1)
		{
			printf("C\n");
		}
		else if (cnt == 2)
		{
			printf("B\n");
		}
		else if (cnt == 3)
		{
			printf("A\n");
		}
		else if (cnt == 4)
		{
			printf("S\n");
		}
	}
	return 0;
}