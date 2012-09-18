#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <linux/random.h> 
int main()
{
    int pid = 2131;
    int val = 0;
    
    unsigned int number;
    
    
    for (int i = 0; i<31; i++){
        
        get_random_bytes(&val, sizeof(val));
        val %=2;
        if(val)
            number |= 1 << i;
        else
            number &= ~(1 << i);
          
        }
        
   
    printf("%d\n", (unsigned int)number ^ pid);
}
