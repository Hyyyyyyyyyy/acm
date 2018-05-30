#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MAXN=5e5+100;
const ll MOD=1e9;
ll a[MAXN],sum[31][MAXN];

int main(int argc, char const *argv[]) {
    // freopen("input.txt","r",stdin);
    ll T_T;
    cin>>T_T;
    while(T_T--)
    {
        ll n,m;
        cin>>n>>m;
        a[0]=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n+1);
        for(int i=0;i<31;++i)
            sum[i][0]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<31;++j)
                sum[j][i]=sum[j][i-1]+a[i]/j;
        }
        ll out=0;
        for(int i=1;i<=m;++i)
        {
            ll p;
            scanf("%lld",&p);
            ll pp=p;
            ll lastp=0;
            ll curans=0;
            //printf("p==%lld\n",p);
            for(int j=1;j<31;pp*=p,j++)
            {
                ll curp=upper_bound(a,a+n+1,pp)-a-1;
                //printf("    pp==%lld curp==%lld\n",pp,curp);
                curans=(curans+sum[j][curp]-sum[j][lastp])%MOD;
                lastp=curp;
                if(pp>=a[n])
                    break;
            }
            curans=curans*i%MOD;
            out=(out+curans)%MOD;
            //printf("%lld\n",out);
        }
        printf("%lld\n",out);
    }
    return 0;
}