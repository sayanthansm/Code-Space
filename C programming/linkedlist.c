#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
        return;
    }
    else{
        struct node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void deletefirst(){
    if (head==NULL)
    {
        /* code */
        printf("No value to delete");
        return;
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
}
/*struct node* temp=head;*/
void deletelast(){
    struct node* temp=head;
    if (head==NULL)
    {
        /* code */
        printf("Error");
        return;
    }
    if (head->next==NULL)
    {
        /* code */
        free(head);
        head=NULL;
        return;
    }
    while (temp->next->next!=NULL)
    {
        /* code */
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deletebyval(int val){
    struct node* temp=head;  
    if (head==NULL)
    {
        /* code */
        printf("empty list");
        return;
    }
    struct node* tod;
    if (head->data==val)
    {
        /* code */
        tod=head;
        head=head->next;
        free(tod);
        return;
    }
    while (temp->next!=NULL && temp->next->data!=val)
    {
        /* code */
        temp=temp->next;
    }
    if (temp->next==NULL)
    {
        /* code */
        printf("Not in list");
        return;
    }
    tod=temp->next;
    temp->next=temp->next->next;
    free(tod);   
}
void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Initial list:\n");
    printList();

    printf("\nDeleting 30...\n");
  deletebyval(30);
    printList();

    printf("\nDeleting 10...\n");
  deletebyval(10);
    printList();

    printf("\nTrying to delete 99...\n");
  deletebyval(99); // not in list
    printList();

    printf("\nDeleting first node...\n");
  deletefirst();
    printList();

    printf("\nDeleting last node...\n");
    deletelast();
    printList();

    return 0;
}
