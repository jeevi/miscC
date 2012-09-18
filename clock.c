#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main() {
	
    FILE *fp;
    char *A;
    int *I;
    int secAngle, minAngle, hourAngle;
    int len, tail;
    int temp;
    fp = fopen("input", "r");
    I = (int*)malloc(sizeof(int)*4);
    A = (char*)malloc(sizeof(char)*10);
    
    int j = 0;
    
    while(fgets(A, 10, fp))
    len = strlen(A);
    tail = len - 2;
    
    while(tail>=0){
             
        I[j]  = (A[tail] - '0') + (A[--tail] - '0')*10;
        printf("num = %d\n", I[j]);
        
        tail-=2;
        j++;
    }
    
    
    
    secAngle = I[0]*6;
    minAngle = I[1]*6;
    hourAngle = I[2]*5*6 + (I[1]/ 2);

    temp = hourAngle - minAngle;
    if(temp<0)
        temp*=-1;
    printf("\n\n%d %d %d %d\n\n", secAngle, minAngle, hourAngle, temp);    
    if (temp > 180){
        if ((secAngle > minAngle && secAngle > hourAngle) || (secAngle < hourAngle && secAngle < minAngle)) {
            printf ("\n\nin the smaller sector\n\n");
        }
        else{
        printf ("\n\nin the larger sector\n\n");
        }
     }
    else {
        if ((secAngle > minAngle && secAngle > hourAngle) || (secAngle < hourAngle && secAngle < minAngle)) {
            printf ("\n\nin the larger sector\n\n");
        }
        else{
        printf ("\n\nin the smaller sector\n\n");
        }
        }
        
        
    free(I);
    free(A);
    return 0;
}
