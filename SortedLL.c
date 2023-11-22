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
node * Sort(node **head){
    int temp;
    node * ptr1 = *head;
    node * ptr2=NULL;
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data > ptr2->data){
                temp = ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;

            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return *head;
}

int main(){
    int n,data;

    printf("Enter the element in the List:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the first element %d:\n",i+1);
        scanf("%d",&data);
        head = insert_end(&head,data);
    }
    displayList(&head);
    head=Sort(&head);
    printf("\nAfter Sorting\n");
    displayList(&head);
    return 0;

}
