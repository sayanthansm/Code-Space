#include<stdio.h>
#include<stdlib.h>
void writefile(const char *inp){
    FILE *ptr=fopen(inp,"w");
    if (ptr==NULL)
    {
        printf("File not found\n");
    }
    fprintf(ptr,"holla nigros!");
    fclose(ptr);
    printf("Done writefile\n");
    
}
void enc(const char *file,char k){
    FILE *ptr1=fopen(file,"rb");
    FILE *ptr2=fopen("encrypted.txt","wb");
    if (ptr1==NULL||ptr2==NULL)
    {
        printf("File not found\n");
        exit(1);
    }
    char ch;
    while(fread(&ch,sizeof(ch),1,ptr1)){
        ch^=k;
        fwrite(&ch,sizeof(char),1,ptr2);
    }
    fclose(ptr1);
    fclose(ptr2);
    printf("File encrypted successfully!\n");
}
int main(){
    const char key='k';
    const char *file="sample.txt";
    writefile(file);
    enc(file,key);
    return 0;
}