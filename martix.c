#include<stdio.h>
#include<stdlib.h>

int** allocate(int , int);
void change(int **, int, int);

int main() {

    int row, column, i,j;
//    int *t;
    scanf("%d %d", &row, &column);
    int **mat;
    
    mat = allocate(row, column);

    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
              mat[i][j] = rand()%1000;
        }
     }
     
     for(i=0;i<row;i++){
        for(j=0;j<column;j++){
                printf("%d ", mat[i][j]);
         }
       printf("\n");   
     }
         change(mat, row, column);
         
         
         for(i=0;i<row;i++){
        for(j=0;j<column;j++){
                printf("%d ", mat[i][j]);
         }
       printf("\n");   
     }
}   

void change(int ** mat, int row, int column)     {
    int i, j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
              mat[i][j] = 0;
        }
     }

}
int** allocate(int row, int column){
    
    int ** mat;
    int j;
    mat = (int**)malloc(sizeof(int*)*row);
      
    for(j=0;j<row;j++){
    
            mat[j] = (int*)malloc(sizeof(int)*column);
    }
        
        
    
    return(mat);

}
