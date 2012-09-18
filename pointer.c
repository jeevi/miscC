#include<stdio.h>
void main() {
int *inptr, temp;
temp=10;
inptr=&temp;
char *chptr;
*chptr=*inptr;
printf("%d %d", sizeof(inptr), sizeof(chptr));
}
