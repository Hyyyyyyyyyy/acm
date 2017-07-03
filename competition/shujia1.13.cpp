#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int main()
{
    int i, j, k, a, b, n, m;
    while(scanf("%d", &n) != EOF)
    {
        if(n >= 4 && n % 2 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
