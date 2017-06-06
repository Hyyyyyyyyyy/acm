#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
int main()
{
    int i, j, k, ar[maxn], s, t, cnt;
    while(scanf("%d", &n) != EOF && n)
    {
        cnt = s = t = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
            s ^= ar[i];
        }
        for(i = 1; i <= n; i++)
        {
            t = s ^ ar[i];
            if(t < ar[i])
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}