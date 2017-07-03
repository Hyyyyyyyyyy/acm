#include<string>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
double rates;
long long n,m;
double C[105][105];
void init()
{
    int i,j;
    C[0][0]=0;
    for(i=1;i<105;i++)C[i][0]=1,C[i][i]=1;
    for(i=2;i<105;i++)
    {
        for(j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
int main()
{
    int T;
    ll i,j;
    init();
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%lld%lld",&n,&m);
            if(n<m)
            {
                printf("%%0\n");
                continue;
            }
            rates=1;
            for(i=1;i<m;i++)
            {
                if(i&1)rates-=C[m][i]*pow(1.0*(m-i)/m,n);
                else rates+=C[m][i]*pow(1.0*(m-i)/m,n);
            }
            rates*=100;
            printf("%%");
            if(rates<0)
            {
                printf("0\n");
            }
            else printf("%.0f\n",rates);
        }
    }
}