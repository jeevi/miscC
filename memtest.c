#include<stdio.h>

void main (){

    int a = 9;
    int *z, *y;
    z = &a;
    y = &z;
    printf ("%d %d\n", z, y);
    
}
    


