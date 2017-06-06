#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int main()
{
    int i, j, k, u, a, b, c, n, m, d, bag[500010];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            for(i = 0; i <= d; i++)
            {
                bag[i] = MIN;
            }
            bag[0] = 0;
            ar[1] = a;
            ar[2] = b;
            ar[3] = c;
            for(i = 1; i <= 3; i++)
            {
                for(j = 0; j <= d; j++)
                {
                    bag[j] = (bag[j] > bag[j - ar[i]] + ar[i]) ? bag[j]:(bag[j - ar[i]] + ar[i]);
                }
            }
            if(bag[d] != MIN)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}