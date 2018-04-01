//单点更新，单点查询
int ar[maxn];
int Bit[maxn];
int N;
void Add(int x, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		Bit[i] += val;
	}
}
int Sum(int x)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += Bit[i];
	}
	return res;
}
int main()
{
    memset(Bit, 0, sizeof(Bit));
    for (n = 1; n <= N; n++)
    {
        scanf("%d", &ar[n]);
    }
    //单点查询 查询a
    scanf("%d", &a);
    printf("%d\n", ar[a] + Sum(a) - Sum(a-1));
    //单点修改  把a加c
    scanf("%d %d", &a, &c);
    Add(a, c);

}


//单点更新，区间查询
int ar[maxn];
int Bit[maxn];
int sum[maxn];
int N;
void Add(int x, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		Bit[i] += val;
	}
}
int Sum(int x)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += Bit[i];
	}
	return res;
}
int main()
{
    memset(Bit, 0, sizeof(Bit));
    sum[0] = 0;
    for (n = 1; n <= N; n++)
    {
        scanf("%d", &ar[n]);
        sum[n] = sum[n - 1] + ar[n];
    }
    //区间查询 查询[a,b]
    scanf("%d %d", &a, &b);
    printf("%d\n", sum[b] - sum[a-1] + Sum(b) - Sum(a-1));
    //单点修改 把a加c
    scanf("%d %d", &a, &c);
    Add(a, c);

	return 0;
}




//区间更新， 单点查询
int ar[maxn];
int Bit[maxn];
int N;
void Add(int x, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		Bit[i] += val;
	}
}
int Sum(int x)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += Bit[i];
	}
	return res;
}
int main()
{
    memset(Bit, 0, sizeof(Bit));
    for (n = 1; n <= N; n++)
    {
        scanf("%d", &ar[n]);
    }
    //单点查询 查询a
    scanf("%d", &a);
    printf("%d\n", ar[a] + Sum(a));
    //区间更新(差分法) 更新[a,b] + c
    scanf("%d %d %d", &a, &b, &c);
    Add(a, c);
    Add(b + 1, -c);
	return 0;
}






//区间更新，区间查询
