#include <iostream>  
#include <string.h>  
#include <stdio.h>  
  
using namespace std;  
const int N = 50005;  
typedef long long LL;  
const LL INF = (((LL)1)<<62)+1;  
  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
  
LL ans;  
int n;  
int d[N];  
  
void Init()  
{  
    for(int i=1;i<N;i++) d[i] = i;  
    for(int i=1;i<N;i++)  
    {  
        for(int j=i;j<N;j+=i) d[j]--;  
        if(!d[d[i]]) d[d[i]] = i;  
        d[i] = 0;  
    }  
}  
  
void dfs(int dept,int limit,LL tmp,int num)  
{  
    if(num > n) return;  
    if(num == n && ans > tmp) ans = tmp;  
    for(int i=1;i<=limit;i++)  
    {  
        if(ans / p[dept] < tmp || num*(i+1) > n) break;  
        tmp *= p[dept];  
        if(n % (num*(i+1)) == 0)  
            dfs(dept+1,i,tmp,num*(i+1));  
    }  
}  
  
int main()  
{  
    Init();  
    int T,tt=1;  
    scanf("%d",&T);  
    while(T--)  
    {  
        int type;  
        scanf("%d%d",&type,&n);  
        if(type) ans = d[n];  
        else  
        {  
            ans = INF;  
            dfs(0,62,1,1);  
        }  
        printf("Case %d: ",tt++);  
        if(ans == 0) puts("Illegal");  
        else if(ans >= INF) puts("INF");  
        else printf("%I64d\n",ans);  
    }  
    return 0;  
}  