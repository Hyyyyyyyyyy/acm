#include <stdio.h> 
int main()
{
    char name[40];
    float cash;
    scanf("%s", &name);
    scanf("%f", &cash);
    printf("The %s family just may be $%.2f dollars richer.\n", name, cash);

    return 0;
}
