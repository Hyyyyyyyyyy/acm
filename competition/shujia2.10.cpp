#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 100000000;
bool ar[10];
int main()
{
	int n, S, T;
	while (scanf("%d %d %d", &n, &S, &T) != EOF)
	{
		memset(ar, false, sizeof(ar));
		for (int i = 0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			ar[x] = true;
		}
		if (T == S)
		{
			printf("0\n");
			continue;
		}
		int res = INF;
		res = min(res, abs(T - S));
		for (int i = 0; i <= 500000; i++)
		{
			bool doudou = true;
			int count = 0, temp = i;
			while (temp)
			{
				if (ar[temp % 10])
				{
					doudou = false;
					break;
				}
				temp = temp / 10;
				count++;
			}
			if (doudou)
			{
				if (i == 0 && !ar[0])
					res = min(res, abs(i - T) + 1);
				if (i != 0)
					res = min(res, abs(i - T) + count);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}