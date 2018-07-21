#include <cstdio>
#include "iostream"
#include <cstring>
#include <algorithm>
#include <cmath>
#include "string"
#include <vector>
#include "set"
#include "queue"
#include "string"
using namespace std;
#define FOP freopen("input.txt","r",stdin)
#define Met(x,y) memset(x,y,sizeof x)
typedef long long ll;
const ll INF = 1e18;
const ll MOD=1e9+7;
const ll MAXN=2e3+100;
ll dp[MAXN][MAXN];
ll vol[2][MAXN];
ll w[2],len[2];
ll sum[2][MAXN];
int main(int argc, char const *argv[]) {
    // FOP;
    ll T_T;
    while(cin>>T_T)
	{
		while(T_T--)
		{
			ll c;
			cin>>w[0]>>w[1]>>c;
			cin>>len[0]>>len[1];
			Met(sum,0);
			for(int i=0;i<2;++i)
				for(int j=1;j<=len[i];++j)
				{
					scanf("%lld",&vol[i][j]);
				}
			for(int i=0;i<2;++i)
				sort(vol[i]+1,vol[i]+1+len[i]);
			for(int i=0;i<2;++i)
				for(int j=1;j<=len[i];++j)
					sum[i][j]=sum[i][j-1]+vol[i][j];
			Met(dp,0);
			ll ans=0;
			for(int i=0;i<=len[0];++i)
				for(int j=0;j<=len[1];++j)
				{
					ll curv=sum[0][i]+sum[1][j];
					if(c<=sum[0][i]+sum[1][j]) break;
					// if(i==1 && j==0)
					//     printf("info %lld %lld %lld",dp[i-1][j],w[0],c-curv);
					if(j)
						dp[i][j]=max(dp[i][j],dp[i][j-1]+w[1]*(c-curv));
					if(i)
						dp[i][j]=max(dp[i][j],dp[i-1][j]+w[0]*(c-curv));
					ans=max(ans,dp[i][j]);
				}

			// for(int i=0;i<=len[0];++i)
			//     for(int j=0;j<len[1]+1;j++)
			//         printf("%lld%c",dp[i][j],j==len[1]+1-1?'\n':' ');
			cout<<ans<<endl;
		}
	}
    return 0;
}
