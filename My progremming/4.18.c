#include <stdio.h>
int main()
{
    int n = 0;
    int m = 1;
    size_t intsize;
    intsize = sizeof (int);
    printf("n = %d, m = %d, n and m has %u bytes; all ints have %u bytes.\n", n, m, sizeof n, intsize);

    return 0;
}
