#include<stdio.h> //apart from changing directory 
#include<stdlib.h>
#include<string.h>
void executecommand(char command[]) {
    int res = system(command);
    if (res == 0) {
        printf("Command executed successfully\n");
    } else {
        printf("Command not executed\n");
    }
}


int main(){
    printf("Welcome to simple command prompt!!\n");
    while (1)
    {
    printf("Enter the command to execute:\n");
    char* command=(char *)malloc(256*sizeof(char));
    if(fgets(command, 256, stdin)==NULL){
        free(command);
        continue;
    }
      command[strcspn(command, "\n")] = 0;
    
    if (strcmp(command,"exit"));
    {
        break;
    }
    executecommand(command);
    free(command);
    
    }

    return 0;
}
