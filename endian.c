#include<stdio.h>


void secondtest();
void main(){

    int i = 1;
    char *p = &i;
    if(*p==1)
        printf("little endian\n");
    else
        printf("big endian\n");
        
    secondtest();
}

void secondtest(){

    union check{
    
        int i;
        char a;
    };
    
    union check d;
    d.i = 1;
    printf("%d\n", d.a);
}
