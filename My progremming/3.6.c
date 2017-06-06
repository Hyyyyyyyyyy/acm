#include<stdio.h>
int main ()
{
    char EE, NN, TT;
    printf("Please enter three characters,\n");
    scanf("%c %c %c",&EE, &NN, &TT);
    printf("The code for %c %c %c is %d %d %d,\n",EE, NN, TT, EE, NN, TT);

    getchar();
    getchar();
	return 0;
}
