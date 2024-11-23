#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void calc(int a ,int b){
    char* option=(char *)malloc(10*sizeof(char));
    if (option==NULL)
    {
        printf("Memory not allocated");
    return;
    }

    
    printf("Enter the option:");
    scanf("%9s",option);
    if (strcmp(option,"add")==0)
    {
        printf("%d",a+b);
    }
    if (strcmp(option,"sub")==0)
    {
        printf("%d",a-b);
    }
    if (strcmp(option,"multiply")==0)
    {
        printf("%d",a*b);
    }
    if (strcmp(option,"div")==0)
    {
        if (b==0)
        {
            printf("Error: Division by zero is not allowed");
        }
        
        printf("%d",a/b);
    }
    if (strcmp(option,"mod")==0)
    {
        printf("%d",a%b);
    }
    free(option);
    
}
int main(){ 
    int c,d;
    printf("Enter a:");
    scanf("%d",&c);
    printf("Enter b:");
    scanf("%d",&d);
    calc(c,d);
    return 0;


}