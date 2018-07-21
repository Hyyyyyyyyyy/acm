//找暴力寻环节
// #include <cstdio>
// #include <cstring>
// #include <cstdlib>
// #include <algorithm>
// #include <cmath>
// #include <set>
// #include <map>
// #include <cctype>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <string>
// #include <iostream>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// #define foR for
// #define for9 for
// #define retunr return
// #define reutrn return
// #define reutnr return
// #define retrun return
// const int inf = 1e8;
// const ll INF = (1ll << 63) - 1;
// const double PI = acos(-1.0);
// const double eps = 1e-7;
// ll MOD = 1000000007ll;
// const int maxn = 100000 + 100;
// const int maxm = 400000 + 100;
// int main()
// {
//     ll i, j, k;
//     ll a, b;
//     a = 1;
//     b = 0;
//     for(i = 1;;i++)
//     {
//         ll t = a;
//         a = (3*a+b) % MOD;
//         b = t;
//         if(a == 1 && b == 0)
//         {
//             if(i != MOD)
//             {
//                 printf("%lld\n", i);
//                 MOD = i;
//                 i = 0;
//             }
//             else
//                 break;
//         }
//     }
//     return 0;
// }
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
ll N;
struct Matrix
{
	ll a[2][2];
};
//222222224
//183120
//240
inline Matrix MULMatrix(Matrix A, Matrix B, ll mod)
{
	ll i, j, k;
	Matrix res;
	res.a[0][0] = res.a[1][1] = 0;
	res.a[0][1] = res.a[1][0] = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				res.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
				res.a[i][j] %= mod;
			}
		}
	}
	return res;
}
inline Matrix quickMULMatrix(Matrix A, ll n, ll mod)
{
	ll i, j, k;
	Matrix res;
	res.a[0][0] = res.a[1][1] = 1;
	res.a[0][1] = res.a[1][0] = 0;
	while (n)
	{
		if (n & 1)
		{
			res = MULMatrix(res, A, mod);
		}
		A = MULMatrix(A, A, mod);
		n >>= 1;
	}
	return res;
}
int main()
{
	ll i, j, k;
	Matrix A, B;
	A.a[0][0] = 1;
	A.a[0][1] = A.a[1][0] = A.a[1][1] = 0;
	B.a[0][0] = 3;
	B.a[0][1] = B.a[1][0] = 1;
	B.a[1][1] = 0;
	while (scanf("%lld", &N) != EOF)
	{
		if (N == 0)
		{
			printf("0\n");
			continue;
		}
		if (N == 1)
		{
			printf("1\n");
			continue;
		}
		N %= 240;
		Matrix T = quickMULMatrix(B, N, 183120ll);
		T = MULMatrix(T, A, 183120ll);

		N = T.a[1][0];
		T = quickMULMatrix(B, N, 222222224ll);
		T = MULMatrix(T, A, 222222224ll);

		N = T.a[1][0];
		T = quickMULMatrix(B, N, 1000000007ll);
		T = MULMatrix(T, A, 1000000007ll);
		printf("%lld\n", T.a[1][0]);
	}
	return 0;
}
//4291     暴力找循环节+矩阵快速幂
//222222224
//183120
//240