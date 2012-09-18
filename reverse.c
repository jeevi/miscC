#include<stdio.h>

int main() {
    
    int num, flag = 0;
    int A[10];
    int temp;
    scanf("%d", &num);
    
    if(num<0){
        num*=-1;
        flag = 1;   
    }
    int i = -1;
    while(num){
    
        A[++i] = num%10;
        num=num/10;
    }
    temp=i;
    int j = 0;
    
    while(j<i){
    
        if(A[j]==A[i])
            A[j] = -1;
        j++; i--;
        printf("here");
    }
    
   // i = (sizeof(A)/ sizeof(A[0])) - 1;
    //printf("%d", i);
    i=temp;
    num = 0;
    while(i!=-1){
        if(A[i]<0){
            i--;
            continue;
        }
        num= num*10+A[i];
        i--;
    }
    
    if(flag)
        num*=-1;
    printf("%d", num);
    
    return 0;
}
