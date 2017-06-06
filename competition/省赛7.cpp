#include <cstdio>
#include <iostream>
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
int ar[100005];
int AL[100005];
int main()
{
    int i, j, k, a, b, c, n, m, u, doudou;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            for(u = 1; u <= k; u++)
            {
                scanf("%d", &ar[u]);
            }
            for(u = 1; u <= k; u++)
            {
                scanf("%d", &AL[u]);
            }
            if((AL[k] == 1 && ar[k] % 2 == 0) || (AL[k] == 2 && ar[k] % 2 != 0))
            {
                printf("Bob\n");
            }
            else
            {
                doudou = 1;
                for(i = 1; i < k; i++)
                {
                    if(AL[i] == 1 && ar[i] % 2 != 0)
                    {
                        doudou = 0;
                        if(AL[i+1] != 0)
                            break;
                        else
                            doudou = 1;
                    }
                    if(AL[i] == 2 && ar[i] % 2 == 0)
                    {
                        doudou = 0;
                        if(AL[i+1] != 0)
                            break;
                        else
                            doudou = 1;
                    }
                }
                if(doudou)
                    printf("Alice\n");
                else
                    printf("Bob\n");
            }
        }
    }
    return 0;
}
