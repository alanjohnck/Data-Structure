#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node * next;
}node;
node * front=NULL;
node * head =NULL;
node * create_node(int data){
    node * newnode = malloc(sizeof (node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void Enqueue(int data){
    node * newnode = create_node(data);
    if(front == NULL){
        front = newnode;
    }else{
        node * temp = front;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
}
void push(node * temp){
    temp->next = head;
    head =temp;

}