#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1.0e-9;
const int maxn = 110;
typedef long long ll;
ll mod;
ll zushu, var;
ll a[maxn*maxn][maxn*maxn], x[maxn*maxn];
ll Determinant()
{
	ll i, j, k, u;
	ll res = 1;
	ll sign = 1;
	for (i = 1; i <= zushu; i++)
	{
		for (j = i + 1; j <= zushu; j++)
		{
			ll point1 = i;
			ll point2 = j;
			while (a[point2][i])
			{
				ll coe = a[point1][i] / a[point2][i];
				for (u = i; u <= var; u++)
				{
					a[point1][u] = ((a[point1][u] - coe * a[point2][u]) % mod + mod) % mod;
				}
				swap(point1, point2);
			}
			if (point1 != i)
			{
				sign *= -1;
				for (u = i; u <= var; u++)
					swap(a[point1][u], a[point2][u]);
			}
		}
		if (!a[i][i])
			return 0;
	}
	for (i = 1; i <= zushu; i++)
		res = ((res * a[i][i]) % mod + mod) % mod;
	res = ((res * sign) % mod + mod) % mod;
	return res;
}