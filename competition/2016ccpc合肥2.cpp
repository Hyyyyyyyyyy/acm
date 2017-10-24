#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const int MOD = 1e9 + 7;
const int maxn = 11000;
ll N, M;
char temp[maxn];
int a[maxn];
int ch[maxn];
int ans[3];
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            scanf("%s",temp);
            int len=strlen(temp);
            for(int i=0;i<len;++i) a[i]=temp[i]-'0';
            for(int k=0;k<3;++k){
            ch[0]=k;
            ans[0]=1;
            for(int i=1;i<len;++i)
            {
                if(a[i-1]-ch[i-1]-(i==1)?0:ch[i-2]>2)
                {
                    ans[k]=0; 
                    break;
                }
                else if(a[i-1]-ch[i-1]-(i==1)?0:ch[i-2]==1)
                    ans[k]=(ans[k]*2)%MOD;
            }
            }
            printf("%d",(ans[0]+ans[1]+ans[2])%MOD);
        }
    }
    
    return 0;
}
