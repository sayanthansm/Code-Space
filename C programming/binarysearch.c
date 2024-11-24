#include<stdio.h>
#include<stdlib.h>
void bubblesort(int a[],int size){
    for (int i = 0; i < size-1; i++)
    {
        for(int j=0;j<size-i-1;j++){
            if (a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            
        }
        
    }
    
}
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        
        if (arr[mid] == target) {
            return mid;  
        }
        
        
        if (arr[mid] > target) {
            right = mid - 1;
        }
        
        else {
            left = mid + 1;
        }
    }
    
    return -1;  
}


int main(){
    int n;
    printf("Enter array size:\n");
    scanf("%d",&n);
    int* ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }
    
    int target;
    printf("Enter target element search:\n");
    scanf("%d",&target);
    bubblesort(ar,n);
    int result=binarySearch(ar,n,target);
     if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    free(ar);
    return 0;
    
}