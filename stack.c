#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct mystack{

    int data;
    struct mystack *next;

};

int elem;

void createstack(struct mystack **);
void deletestack(struct mystack **);
int push(struct mystack **);
int pop(struct mystack **, int*);
int printstack(struct mystack *);
int newNode(struct mystack **);

int main(){


    int d;
    int flag = 1;
    struct mystack *head;
  
    createstack(&head);
    
    printf("enter number of elements to be added");
    scanf("%d", &elem);
    
    push(&head);
               
    printf("\npushing done\n\n");
    
    printstack(head);
    sleep(5);
    while(flag){
     
        printf("\n%d\n", pop(&head, &d));
        if(!d)
            flag = 0;
    }
    
    
    return 0;

}


void createstack(struct mystack **head){

    *head = NULL;
    
}


int push(struct mystack **head){

    struct mystack *temp = *head;
    
    if(temp==NULL){
    
        temp = (struct mystack*)malloc(sizeof(struct mystack));
        if(!temp)
            return 0;
        temp->data = rand()%100;
        temp->next = NULL;
        *head = temp;
        elem--;
    }
    
    while(elem){
    
        if(!newNode(head))
            return 0;
        elem--;
    }   
    return 1; 
}

int newNode(struct mystack **head){
        
        struct mystack * t = (struct mystack*)malloc(sizeof(struct mystack));
        if(!t)
            return 0;
    
        t->data = rand()%100;
        t->next = *head;
        *head = t;
        printf("\npushing %d\n", t->data);                
        return 1;
}


int printstack(struct mystack *head) {

    struct mystack *temp = head;
    
    while (temp){
    
        printf("\n%d\n", temp->data);
        if(!temp->next){
            
            return 1;
         }
        temp = temp->next;
    
    }

}

int pop(struct mystack **head, int *val){

    
    struct mystack *temp1 = *head;
    int temp2;
    
    if(temp1 == NULL){
        printf("stack empty");
        *val = 0;
        return 0; 
    }
    
    else {
    
        temp1 = (*head)->next;
        temp2 = (*head)->data;
//        printf("in pop %d", temp2);
        free(*head);
        *head = temp1;
        *val = 1;   
        
    }
    
     
     return temp2;
    
}

