#include<stdio.h>
#include<stdlib.h>

struct tree{

    int data;
    struct tree* left;
    struct tree* right;
};

struct queue{
    
    struct tree *treenode;
    struct queue *next;
    struct queue *prev;

};

int main(){

    struct tree* root;
    int node;  
    scanf("%d", &node);
    
    if(!inittree(&root))
        fprintf("cannot initialise the root", stderr);
    
    growtree(&root, node);
    
    printtree(root);
    return 0;
}

int inittree(struct tree **root){

    *root = NULL;
    if(!*root)
        return 0; 
    return 1;
}

int growtree(struct tree **root, int node){

    if(*root==NULL){
    
        struct tree *tnode = (struct tree *)calloc(sizeof(struct tree), 0);
        if(!tnode)
            return 0;
        tnode->data = rand()%1000;
        tnode->left = NULL;
        tnode->right = NULL;
        *root = tnode;
        node--;
    }

    struct queue *head, *tail;
    struct queue *elem = (struct queue *)calloc(sizeof(struct queue), 0);
    if(!elem)
        return 0;
    elem->treenode = tnode;
    elem->next = NULL;
    elem->prev = NULL;
    head = elem;
    tail = elem;

    int l = 1;

    while(node) {

        for(i = 0; i < 2^l ; i+=2 ) {  

            if(tail->treenode->left == NULL && tail->treenode->right == NULL) {
            
                if(!add(&head, &tail))    return 0;
                if(!add(&head, &tail))   return 0;
                node-=2;
            }
        
        }
        
        l++;
            
    }

}


int add(struct queue **head, struct queue **tail) {

    struct tree *temp = (struct tree *)calloc(sizeof(struct tree), 0);
    if(!temp)
        return 0;

    temp->left = NULL;
    temp->right = NULL;
    temp->data = rand()%1000;
    
    struct queue *temp1 = (struct queue *)calloc(sizeof(struct queue), 0);
    struct queue *temp2;
    if(!temp1)
        return 0;

    temp1->treenode = temp;
    temp1->next = *head;
    (*head)->prev = temp1;
    *head = temp1;
    temp2 = *tail;
    *tail = *tail->prev;
    free(temp2);

}
