#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10001;
int ar[110], cur[maxn], pre[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (cin >> n)
	{
		memset(pre, 0, sizeof(pre));
		memset(cur, 0, sizeof(cur));
		int sum = 0;
		for (m = 1; m <= n; m++)
		{
			cin >> ar[m];
			sum += ar[m];
		}
		for (i = 0; i <= ar[1]; i += ar[1])
			pre[i] = 1;
		for (i = 2; i <= n; i++)
		{
			for (j = 0; j <= sum; j++)
			{
				for (k = 0; k <= ar[i] && k + j <= sum; k += ar[i])
				{
					cur[k + j] += pre[j];
					if (k > j)
						cur[k - j] += pre[j];
					else
						cur[j - k] += pre[j];
				}
			}
			for (j = 0; j <= sum; j++)
			{
				pre[j] = cur[j];
				cur[j] = 0;
			}
		}
		int cnt = 0;
		for (i = 1; i <= sum; i++)
		{
			if (!pre[i])
			{
				cnt++;
			}
		}
		cout << cnt << endl;
		int doudou = 0;
		for (i = 1; i <= sum; i++)
		{
			if (!pre[i])
			{
				if (doudou)
					cout << " ";
				cout << i;
				doudou = 1;
			}
		}
		if (cnt)
			cout << endl;
	}
	return 0;
}
