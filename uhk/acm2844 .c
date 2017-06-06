#include <stdio.h>
struct coin
{
    int value;
    int num;
};
int main()
{
    int n, m, i, j, k, bag[100005], mvalue, c, count;
    struct coin Hibix[105];
    while(scanf("%d %d", &c, &mvalue) != EOF && (c != 0 || mvalue != 0))
    {
        for(m = 1; m <= c; m++)
            scanf("%d", &Hibix[m].value);
        for(m = 1; m <= c; m++)
            scanf("%d", &Hibix[m].num);
        for(i = 1; i < mvalue; i++)
            bag[i] = -100005;
        bag[0] = 0;
        for(i = 1; i <= c; i++)
        {
            if(Hibix[i].value*Hibix[i].num < mvalue)
            {
                k = 1;
                while(k < Hibix[i].num)
                {
                    for(j = mvalue; j >= k*Hibix[i].value; j--)
                    {
                        bag[j] = (bag[j] > bag[j-k*Hibix[i].value]+Hibix[i].value) ? bag[j]:(bag[j-k*Hibix[i].value]+Hibix[i].value);
                    }
                    Hibix[i].num -= k;
                    k *= 2;
                }
                for(j = mvalue; j >= Hibix[i].num * Hibix[i].value; j--)
                {
                    bag[j] = (bag[j] > bag[j-Hibix[i].num * Hibix[i].value]+Hibix[i].value) ? bag[j]:(bag[j-Hibix[i].num * Hibix[i].value]+Hibix[i].value);
                }
            }
            else
            {
                for(j = Hibix[i].value; j <= mvalue; j++)
                {
                    bag[j] = (bag[j] > bag[j- Hibix[i].value]+Hibix[i].value) ? bag[j]:(bag[j-Hibix[i].value]+Hibix[i].value);
                }
            }
        }
        count = 0;
        for(j = 1; j <= mvalue; j++)
        {
            if(bag[j] > 0)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
