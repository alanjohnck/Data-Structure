#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node*  front = NULL, * rear = NULL;
node * Enqueue(node **rear ,node **front, int data){
    node * newnode = malloc(sizeof (node));
    if(*rear==NULL) {
        newnode->data = data;
        newnode->next = NULL;
        (*front) = newnode;//to get fist node address
        (*rear) = newnode;
    }else {
        newnode->data = data;
        newnode->next =NULL;
        (*rear)->next = newnode;
        (*rear) = (*rear)->next;
    }
    return *rear;
}
node * Dequeue(node**front){
    if(*front==NULL){
        printf("Queue is empty");
    }
    node * temp =*front;
    printf("The deleted element is  : %d",temp->data);
    (*front)=(*front)->next;
    free(temp);
    return *front;
}
void display(node**front){
    node *temp = *front;//to get front address,taking copy of address otherwise it will leads to change in front pointer address ,the reference will be lost
    if((temp)==NULL){
        printf("Queue is empty");
    }else{
        while((temp)!=NULL){
            printf("%d -> ",temp -> data);
            temp= temp->next;
        }
        printf("NULL");
    }


}
int main (){
    int data, i;
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.display\n");
        scanf("%d", &i);
        switch(i){
            case 1:
                printf("Enter the data to Enqueue:");
                scanf("%d", &data);
                rear = Enqueue(&rear,&front, data);//should use & otherwise copy will remain and there will no change
                break;
            case 2:
                front = Dequeue(&front);
                break;
            case 3:
                 display(&front);
                break;
        }
    } while (i != 10);
    return 0;
}
