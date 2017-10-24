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
char s[maxn];
int ch[maxn];
int ans[3];
int dp[maxn];
int main()
{
    int n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
    	int ans=0;
    	for (int i=0;i<=2&&i<=s[1]-'0';i++)
    	{
            dp[1]=i;
            bool jud=true;
            for (int j=2;j<=n;j++)
            {
                int num=s[i-1]-'0'-dp[j-1]-dp[j-2];
                if (num>2||num<0)
                {
                    jud=false;
                    break;
                }
                dp[j]=num;
            }
        }
        if (jud && dp[n-1]+dp[n]==s[n]-'0')
        {
            int now=1;
            for (int j=1;j<=n;j++)
            {
                if (dp[j]=1) now*=2;

                now % =MOD;
            }
            ans+=now;
            ans % = MOD;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}