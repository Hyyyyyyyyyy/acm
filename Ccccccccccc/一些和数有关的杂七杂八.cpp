void init(__int64 n)//求一个数的质因子
{
    __int64 i;
    num=0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a[num++]=i;
            while(n%i==0)
                n=n/i;
        }
    }
    if(n>1)//这里要记得
        a[num++]=n;
}

//筛选法求出所有素因子  
int prime[100005][20];  
int cnt[100005]={0};  
void Init(){  
    for(int i=2;i<=100000;i++){  
        if(cnt[i]) continue;  
        prime[i][0]=i;  
        cnt[i]=1;  
        for(int j=2;j*i<=100000;j++)  
            prime[i*j][cnt[i*j]++]=i;  
    }  
}  

