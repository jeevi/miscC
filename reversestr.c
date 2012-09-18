#include<stdio.h>
#include<string.h>
char reverse(char[]);
int main() {

    char str[100];
    
    fgets(str, 100,  stdin);
           
    printf("\n\n%d\n\n", strlen(str));
    reverse(str);

}


char reverse(char *str){

    if(*str=='\0')  
        return;
    else{
        reverse(str+1);
        printf("%c", *str);
        
    }
}
