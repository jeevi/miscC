#include<stdio.h>
#include<string.h>

int main(){
int n;
scanf("%d", &n);
if(!n)
    return 0;
    
int a[n];
int i = 0;
while(i!=n){

    scanf("%d", &a[i]);
    i++;
}

int smax, max;
max = -999999;
smax = -999999;
for(i = 0; i< n; i++){

    if(a[i]>max){
        smax = max;
        max = a[i];
    }
    else if(a[i]>smax && max>a[i])
        smax = a[i];
    
}


printf("\n%d %d\n", smax, max);
return 0;
}
