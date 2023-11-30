#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char data;
    struct node * next;
    struct node * prev;
}node;

node * head=NULL;

node * create_node (char data){
    node * newnode = malloc(sizeof (node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void insert(char data){
    node * newnode = create_node(data);
    if(head==NULL){
        head=newnode;
    }else{
        node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

bool pallindrome(node * head){
    node * ptr1=head;
    node * ptr2=head;
    while(ptr2->next!=NULL){
        ptr2=ptr2->next;
    }
    while(ptr1!=ptr2){
        if(ptr1->data!=ptr2->data){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->prev;
    }
    return true;
}

int main(){
    char str[]="malayalam";
    for(int i=0;str[i]!='\0';i++){
        insert(str[i]);
    }
    bool dec = pallindrome(head);
    if(dec){
        printf("It is pallindrome\n");
    }else{
        printf("It is not pallindrome\n");
    }
    return 0;
}
