//单点更新，单点查询
void update(int x, int val)
{
    int t = x;
    while(t <= N)
    {
        c[t] += val;
        t += t & -t;
    }
}
int sum(int x)
{
    int t = x;
    int res = 0;
    while(t >= 1)
    {
        res += c[t];
        t -= t & -t;
    }
    return res;
}
update(x);
sum(x);


//单点更新，区间查询
void update(int x, int val)
{
    int t = x;
    while(t <= N)
    {
        c[t] += val;
        t += t & -t;
    }
}
int sum(int x)
{
    int t = x;
    int res = 0;
    while(t >= 1)
    {
        res += c[t];
        t -= t & -t;
    }
    return res;
}
update(x);
sum(y) - sum(x-1);




//区间更新， 单点查询
void update(int x, int val)
{
    int t = x;
    while(t <= N)
    {
        c[t] += val;
        t += t & -t;
    }
}
int sum(int x)
{
    int t = x;
    int res = 0;
    while(t >= 1)
    {
        res += c[t];
        t -= t & -t;
    }
    return res;
}
update(x, v);
update(y+1, -v);
sum(x);





//区间更新，区间查询
