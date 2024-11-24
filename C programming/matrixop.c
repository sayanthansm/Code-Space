#include<stdio.h>
#include<string.h>
void matrixini1(int k,int l,int a[k][l]){
    
    printf("Enter the values: \n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            scanf("%d", &a[i][j]);
        }
        
    }
    printf("The matrix is: \n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++){
            printf("%d ",a[i][j]);
        }
    }
    
}

    

void add(int q,int e,int a[q][e],int b[q][e],int res[q][e]){
    for (int i = 0; i <q ; i++)
    {
        for (int j = 0; j < e; j++)
        {
            res[i][j]=a[i][j]+b[i][j];
        }
        
    }
    for (int i = 0; i <q ; i++)
    {
        for (int j = 0; j < e; j++)
        {
            printf("%d ",res[i][j]);
        }
        
    }
    
}

int main(){
    int o,p;
    printf("Enter number of rows,columns\n " );
    scanf("%d %d",&o,&p);
    int matrix1[o][p];
    int matrix2[o][p];
    int result[o][p];
    matrixini1(o,p,matrix1);
    matrixini1(o,p,matrix2);
    char op[10];
    printf("Enter the operation you want to perform: \n");
    scanf("%s",op);
    if (strcmp(op,"add")==0)
    {
        add(o,p,matrix1,matrix2,result);
    }
    return 0;
    
}