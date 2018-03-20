bool check[maxn];       //true表示不是素数 false是素数
int prime[maxn];        //前tot-1个素数是什么
int tot;                //素数个数是tot-1
void prime_table(int N)
{
    memset(check, false, sizeof(check));
    tot = 0;
    for(int i = 2; i <= N; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > N)
                break;
            check[i * prime[j]] = true;
        }
    }
}
//质数个数 < tot