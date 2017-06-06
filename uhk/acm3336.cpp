#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int Mainl, Assl;
int Sum;
char ar[200010];
int Next[200010], set[200010];
void Cal_Next();
//int KMP();
int main()
{
    int i, j, k, n, m, a, b, sum;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &Mainl);
            scanf("%s", ar+1);
            memset(set, 0, sizeof(set));
            Sum = 0;
            Cal_Next();
            //for(i = 1; i <= Mainl; i++)
            //{
            //    printf("%d ", Next[i]);
            //}
            //for(i = 1; i <= Mainl; i++)
            //{
            //    set[Next[i]]++;
            //}
    
            for(i = 1; i <= Mainl; i++)
            {
                Sum = (set[i] + Sum) % 10007;
            }
            printf("%d\n", (Sum+Mainl)%10007);
        }
    }
    return 0;
}
void Cal_Next()
{
    int i, j, k;
    Next[1] = 0;
    for(i = 2; i <= Mainl; i++)
    {
        j = Next[i-1];
        while(ar[j+1] != ar[i] && j > 0)
        {
            j = Next[j];
        }
        if(ar[j+1] == ar[i])
        {
            Next[i] = j + 1;
            set[Next[i]]++;
        }
        else
            Next[i] = 0;
    }
}