#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int ar[maxn];
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m  <= n; m++)
        {
            scanf("%d", &ar[m]);
        }
        int v = ar[1];
        u = ar[1];
        while(1)
        {
            sort(ar+1, ar+1+n);
            if(u != ar[n])
            {
                ar[n]--;
                u++;
            }
            else
                break;
        }
        pritnf("%d\n", u-v);
    }
    return 0;
}