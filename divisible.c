#include<stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    n = (n<<3)-n;
    if(!(n&1))
        printf("divisible\n");
    else
        printf("not divisible\n");
    printf("\n%d\n", n);
        
    return 0;
}
