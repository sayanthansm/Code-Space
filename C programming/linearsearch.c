#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearsearch(char** a,int size,char data[]){
    int found=0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(a[i],data)==0)
        {
            printf("Found the element %s at %d",a[i],i);
            found=1;
        }
        
    }
     if (!found) {
        printf("Not found\n");
    }

    
}
int main(){
    int n;
    printf("Enter array size:\n");
    scanf("%d",&n);
    char** data=(char **)malloc(n*sizeof(char *));
    if (data==NULL)
    {
        printf("Memory not allocated");
        return 1;
    }
    
    printf("Enter array elements:");
    for(int i=0;i<n;i++){
        for (int i = 0; i < n; i++)
        {
            data[i]=(char *)malloc(n*sizeof(char));
            if (data[i]==NULL)
            {
                printf("Not allocated %d",i);
                return 1;
            }
            scanf("%s",data[i]);
            
        }
        
    }
    char target[20];
    printf("Enter target string:\n");
    scanf("%s",target);
    printf("Performing linear search.....\n");
    linearsearch(data,n,target);
    for (int i = 0; i < n; i++)

    {
    free(data[i]);
    }
    free(data);
    return 0;

}