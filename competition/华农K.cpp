#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
using namespace std;
const int MIN = -100000000;
const int MAX = 100000000;
typedef long long ll;
int ar[1000005], sa[1000005];
int main()
{
    int i, j, k, u, n, m, a, b, max, res, flag, M;
    while(scanf("%d", &n) != EOF)
    {
        max = 0;
        memset(ar, 0, sizeof(ar));
        memset(sa, 0, sizeof(sa));
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            if(a > n)
                continue;
            ar[a]++;
            if(max < a)
                max = a;
        }
        M = 1;
        a = 0;
        for(i = 1; i <= max; i++)
        {
            sa[i] = sa[i-1] + ar[i];
            if(sa[i] != 0)
            	a = (sa[i] % i) ? (sa[i] / i + 1):(sa[i] / i);
            if(M < a)
                M = a;
        }
        printf("%d\n", M);
    }
    return 0;
}
