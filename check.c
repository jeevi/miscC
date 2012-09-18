#include<stdio.h>
#include<stdlib.h>

void main(){
    
    void *key;
    printf("%d", sizeof(key));
    int *r;
    r = (int*)malloc(sizeof(int));
    if(r == 0)
	{
		printf("ERROR: Out of memory\n");
		exit(0);
	}
	*r = 12374;
    key = (void*)r;
    
    printf("%d\n", (*(int*)key));


}
