#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int ar[20];
int main()
{
    int i, j, k, u, n, m, a, b, c, doudou;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            for(u = 1; u <= k; u++)
            {
                scanf("%d", &ar[u]);
            }
            if(k < 10 || k > 13)
            {
                printf("No\n");
                continue;
            }
            sort(ar+1, ar+1+k);
            if(ar[1] != 1)
            {
                printf("No\n");
                continue;
            }
            if(ar[2] != 1)
            {
                printf("No\n");
                continue;
            }
            doudou = 1;
            for(i = 1; i < k-1; i++)
            {
                if(ar[i+1] - ar[i] > 2)
                {
                    doudou = 0;
                    break;
                }
            }
            if(doudou)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}