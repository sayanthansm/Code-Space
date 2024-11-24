#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void guess(int a){
    int b=rand()%100+1;
    if (a==b)
    {
        printf("You guessed it right!\n");
    }
    else{
        printf("You guessed it wrong! The random number generated was %d\n",b);
    }
    

}
int main(){
    int num;
    srand(1200);
    printf("Enter the number to be checked:\n");
    scanf("%d",&num);
    guess(num);
    return 0;
}
