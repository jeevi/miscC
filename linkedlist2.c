#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000

struct list {

    int data;
    struct list *next;
};

struct list *head;
struct list *tail;

int createlist();
int addtolist(int);
int delete(int);
int addafter(int);
int printthelist();
struct list* Newnode(int);

int main(){

    
    int num, del;
    createlist();
        
    printf("enter number of elements to add");
    scanf("%d", &num);
    
    if(!addtolist(num))
        printf("failed to add %d elements", num);
    
    printthelist();
        
    printf("enter element to delete");
    scanf("%d", &del);
    
    if(!delete(del))
        printf("failed to delete item %d", del);
        
    printthelist();
    
    addafter(rand()%num);    
    
    printthelist();
           
    return 0;
}


int createlist(){

    head = NULL;
    tail = NULL;
    return 1;
}

int addtolist(int num){

    struct list *temp1;
    struct list *t;
    
    if(head == NULL && tail == NULL){
    
        printf("emptylist\n");
        temp1 = (struct list*)malloc(sizeof(struct list));
        if(!temp1)
            return 0;
        temp1->data = rand()%100;
        temp1->next = NULL;
        tail = temp1;
        head = temp1;
        num--;
    }
 
    while(num){
 
        Newnode(rand()%100);
        num--;
            
    }
    
}


int printthelist() {

    struct list *temp = head;
    printf("tail %d\n", tail->data);
    printf("head %d\n\n", head->data);
    while(temp){
        printf("%d\n", temp->data);
        if(!temp->next)
            return 1;
        temp = temp->next;
}        
}


struct list* Newnode(int data) {

    struct list *t = (struct list *)malloc(sizeof(struct list));
    if(!t)
      return 0;
    t->data = data;
    t->next = NULL;
    tail->next = t;
    tail = t;
    return(t);
    
}

int delete(int data){
    
    if(data <= 0)
        return 0;
    
    int i = 1;
    struct list* temp = head;
    struct list* t;
    
    if(data == 1) {
        head = head->next;
        free(temp);
        return 1;
    }
    
    while(temp){
        
        if(i == data-1){
            t = temp->next;
            if(!t->next)
                tail = temp;
            temp->next = temp->next->next;
            free(t);
            return 1;
        }
        else {
            temp=temp->next;
            i++;
        }
    }
    
    return 0;
}


int addafter(int data){

    
    struct list *t = (struct list *)malloc(sizeof(struct list));
    if(!t)
      return 0;
      
    t->data = rand(time.ctime())%100;
    printf("\nadding after %d data %d\n", data, t->data);
    if(!data){
        
         t->next = head;
         head = t;
    }
    else{
    
        struct list *temp = head;
        while(data-1){
        
            if(!temp->next){
         
                printf("invalid add index\n");
                return 0;
                
            }
                temp = temp->next;
                data--;
        }
        
        t->next = temp->next;
        temp->next = t;
        if(!t->next)
            tail = t;
    }

}
