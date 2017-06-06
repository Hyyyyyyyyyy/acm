#include <stdio.h>
int main()
{
    double ar[11] = { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 };
    int i;

	printf("»ªÊÏ¶È   "); 
    for (i = 0; i < 11; i++)
        printf("%5.2lf  ", ar[i]);
    putchar('\n');
    for (i = 0; i < 11; i++)
        ar[i] = 5.0/9.0 * (ar[i] - 32.0);
    printf("ÉãÊÏ¶È   ");
    for (i = 0; i < 11; i++)
        printf("%5.2lf  ", ar[i]);
    putchar('\n');

    return 0;
}
