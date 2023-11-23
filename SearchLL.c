
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;
node * head=NULL;
node * insert_end(node **head,int data){
    node * ptr=*head;
    node * newnode=malloc(sizeof (node));
    newnode->data=data;
    newnode->next=NULL;
    if(ptr==NULL){
        (*head)=newnode;
    }else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;

    }
    return *head;
}
void displayList(node **head){
    node * temp=*head;
    printf("The element in the list:");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}
void Search(node ** head,int data){
    int count=0;
    node * temp = *head;
    while(temp!=NULL){
        count++;
        if(temp->data==data){
            printf(" Searched element %d at the position %d",data,count);
            return ;
        }
        temp=temp->next;
    }

}
int main(){
    int n,data,search;
    printf("Enter the element in the List:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the first element %d:\n",i+1);
        scanf("%d",&data);
        head = insert_end(&head,data);
    }
    displayList(&head);
    printf("Enter data to search:");
    scanf("%d",&search);
    Search(&head,search);

}
