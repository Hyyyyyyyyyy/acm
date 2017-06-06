#include <stdio.h>
int main()
{
    int n, m, i1, i2, i3;
    int ten, sixteen, twelve;
    bool doudou = false;

    while (scanf("%d", &n) != EOF && n != 0 && n >= 1000 && n <= 9999)
    {
        doudou = true;
        m = n;
        i1 = 0;
        ten = 0;
        while(m > 0)
        {
            ten += m % 10;
            m /= 10;
            i1++;
        }
        i2 = 0;
        m = n;
        sixteen = 0;
        while (m > 0)
        {
            sixteen += m % 16;
            m /= 16;
            i2++;
        }
        i3 = 0;
        m = n;
        twelve = 0;
        while (m > 0)
        {
            twelve = m % 12;
            m /= 12;
            i3++;
        }

        if(ten == twelve && ten == sixteen)
            printf("%d is a Sky Number.\n", n);
        else
            printf("%d is not a Sky Number.\n", n);
    }
    if(!doudou)
        printf("%d is not a Sky Number.\n", n);

    return 0;
}