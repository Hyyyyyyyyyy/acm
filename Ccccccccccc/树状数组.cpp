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
//Bit1[]和Bit2[]共同表示前缀和数组sum[]，即区间修改区间查询的树状数组不再维护原数组而是维护前缀和数组
//Bit1[i] = ar[i] - ar[i-1]
//Bit2[i] = (i-1) * (ar[i] - ar[i-1])
//sum[n] = n * (Bit1[1] + Bit1[2] + ... + Bit1[n]) - ((1-1)*Bit1[1] + (2-1)*Bit1[2] + (3-1)*Bit1[3] + ... +(n-1)*Bit1[n])
//sum[n] = n * (Bit1[1] + Bit1[2] + ... + Bit1[n]) - (Bit2[1] + Bit2[2] + ... + Bit2[n])
int ar[maxn];
int Bit1[maxn];
int Bit2[maxn];
int N;
void Add1(int x, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		Bit1[i] += val;
	}
}
void Add2(int x, int val)
{
	int i;
	for (i = x; i <= N; i += (i & -i))
	{
		Bit2[i] += val;
	}
}
int Sum1(int x)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += Bit1[i];
	}
	return res;
}
int Sum2(int x)
{
	int i;
	int res = 0;
	for (i = x; i > 0; i -= (i & -i))
	{
		res += Bit2[i];
	}
	return res;
}
int getSum(int a, int b)//a < b
{
	return b * Sum1(b) - Sum2(b) - ((a - 1)*Sum1(a - 1) - Sum2(a - 1));
}
int main()
{
	memset(Bit1, 0, sizeof(Bit1));
	memset(Bit2, 0, sizeof(Bit2));
	ar[0] = 0;
	for (n = 1; n <= N; n++)
	{
		scanf("%d", &ar[n]);
		Add1(n, ar[n]-ar[n-1]);
		Add2(n, (n - 1)*(ar[n] - ar[n - 1]));
	}
	//区间查询 查询[a,b]
	scanf("%d %d", &a, &b);
	printf("%d\n", getSum(a, b));
	//区间修改 [a,b]+c
	scanf("%d %d %d", &a, &b, &c);
	Add1(a, c);
	Add2(a, (a - 1)*c);
	Add1(b + 1, -c);
	Add2(b + 1, b*(-c));

	return 0;
}
