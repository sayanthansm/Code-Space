#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void random(int b){
    int c=rand()%100+1;

    if (b==c)
    {
        printf("Yay! YOu guessed it right\n");
    }
    else{
        printf("Sorry, you guessed it wrong\n");
    }
    printf("The random number was:%d",c);
}
int main(){
    int a;
    srand(time(NULL));
    printf("Enter a number and lets check if the guess is right or wrong:\n");
    scanf("%d",&a);
    random(a);
    return 0;
}