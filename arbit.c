#include<stdio.h>

int main() {

    int a = 5;
    int b = 9;
    int *p = &a;
    int *q = p;
    
    printf("%d %d\n", *p, *q);
    p = &b;
    printf("%d %d\n", *p, *q);
    return 0;

}


