#include<stdio.h>
#include<stdlib.h>

struct mylist{

    int data;
    struct mylist *next;
    
};

void initialise(struct mylist **);
int add(struct mylist **);
int printlist(struct mylist *);

int main(){


  int num = 5;
  struct mylist *head;
  
  initialise(&head);
  while(num){ 
    
    if(!add(&head))
        printf("\nadding new elements failed\n");
    num--;  
  }
  
  printlist(head);
  return 0;
}


void initialise(struct mylist **head){

    *head = NULL;
    printf("\nhead initialised\n");

}

int add(struct mylist **head){

    struct mylist *temp = *head;
    struct mylist *new;

    if(*head==NULL){
        
        temp = (struct mylist*)malloc(sizeof(struct mylist));
        if(!temp)
            return 0;
        temp->data = rand()% 100;
        printf("%d\n", temp->data);
        temp->next = NULL;
        *head = temp;
    }
    
    else {
    
    int i=0;
    
    while (temp){
        i++;
        if(!temp->next)
            break;
        temp = temp->next;
    }
    
    printf("traversed %d\n", i);
    
    new = (struct mylist*)malloc(sizeof(struct mylist));
    if(!new)
        return 0;
        
    
    new->data = rand()% 100;
    printf("%d\n", new->data);
    new->next = temp->next;
    temp->next = new;
    printf("new data added successfully\n");
    
    return 1;
    }
}

int printlist(struct mylist *head){

    struct mylist *temp=head;
        
    if(temp == NULL){
        printf("empty linked list");
        return 0;
    }
        
    while(temp){
    
        printf("\ni am %d\n", temp->data);
        if(!temp->next)
            return 1;
        temp = temp->next;
    }
}  
    


