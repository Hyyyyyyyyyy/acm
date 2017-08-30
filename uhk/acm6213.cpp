#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 1e9 + 1;
const ll MOD = 998244353;
char A[20], B[20];
int main()
{
	int i, j, k, u, n, m;
	map<string, int>q;
	q["rat"] = 1;
	q["ox"] = 2;
	q["tiger"] = 3;
	q["rabbit"] = 4;
	q["dragon"] = 5;
	q["snake"] = 6;
	q["horse"] = 7;
	q["sheep"] = 8;
	q["monkey"] = 9;
	q["rooster"] = 10;
	q["dog"] = 11;
	q["pig"] = 12;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s %s", A, B);
			if (q[A] == q[B])
			{
				printf("12\n");
				continue;
			}
			int res = 0;
			if (q[A] < q[B])
				res = q[B] - q[A];
			else
				res = 12 - q[A] + q[B];
			printf("%d\n", res);
		}
	}
	return 0;
}