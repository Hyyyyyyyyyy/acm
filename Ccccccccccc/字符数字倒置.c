m = cnt;
while (n)
{
    sa[cnt++] = n % 10 + '0';
    n /= 10;
}
for (j = 0; j < (cnt - m) / 2; j++)
{
    t = sa[m + j];
    sa[m + j] = sa[cnt - j - 1];
    sa[cnt - j - 1] = t;
}
