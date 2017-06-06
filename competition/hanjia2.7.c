#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
#define mod 1000007
int  C[105][105];

void init()
{
    int i,j;
    for(i=0;i<105;i++)
    {
        C[i][i]=1;
        C[i][0]=1;
    }
    for(i=2;i<105;i++)
    {
        for(j=1;j<i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            C[i][j]%=mod;
        }
    }
}
int main()
{
    int i,j,T;
    init();
    scanf("%d",&T);
    while(T--)
    {
        int c,r;
        scanf("%d%d",&c,&r);
        int sum=0;
        for(i=1;i<=r;i++)
        {
            sum+=C[c][i];
            sum%=mod;
        }
        printf("%d\n",sum);
    }
}
