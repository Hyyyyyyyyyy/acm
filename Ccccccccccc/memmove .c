#include <string.h>
#include <stdlib.h>
//原型 void memmove(void *s1, const void *s2, size_t n);


int *p1, *p2;
memmove(p1, p2, n*sizeof(int));
//从p2指向的位置，拷贝n字节，到p1指向的位置； p1指向的那个值也被覆盖；
