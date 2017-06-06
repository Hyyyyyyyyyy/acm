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
int ar[50010];
int main()
{
    int i, j, k, u, n, m, a, b, max, res, flag, e, doudou;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
        }
        doudou = 0;
        for(i = n-1; i >= 0; i--)
        {
            for(j = 1; j + i <= n; j++)
            {
                if(ar[j+i] >= ar[j])
                {
                    printf("%d\n", i);
                    doudou = 1;
                    break;
                }
            }
            if(doudou)
            	break;
        }
    }
    return 0;
}
