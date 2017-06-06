#include<stdio.h>
int main()
{
    printf("Type int has a size of %u bytes.\n", sizeof(int));
    printf("Type unsigned int has a size of %u bytes.\n", sizeof(unsigned int));
    printf("Type long int has a size of %u bytes.\n", sizeof(long int));
    printf("Type long long int has a size of %u bytes.\n", sizeof(long long int));
    printf("Type short int has a size of %u bytes.\n", sizeof(short int));
    printf("Type char has a size of %u bytes.\n", sizeof(char));
    printf("Type double has a size of %u bytes.\n", sizeof(double));
    printf("Type float has a size of %u bytes.\n", sizeof(float));
    printf("Type long double has a size of %u bytes.\n", sizeof(long double));
    printf("Type long long has a size of %u bytes.\n", sizeof(long long));
    printf("Type _Bool has a size of %u bytes.\n", sizeof(_Bool));
    printf("Type double _Complex has a size of %u bytes.\n", sizeof(double _Complex));
    printf("Type long double _Complex has a size of %u bytes.\n", sizeof(long double _Complex));
    printf("Type float _Complex has a size of %u bytes.\n", sizeof(float _Complex));

    return 0;
}
