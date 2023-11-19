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
        (*front) = newnode;
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
    printf("The deleted element is: %d",temp->data);
    (*front)=(*front)->next;
    free(temp);
    return *front;
}
void display(node**front){
    node *temp = *front;
    if((temp)==NULL){
        printf("Queue is empty");
    }else{
        while((temp)!=NULL){
            printf("%d\t",temp -> data);
            temp= temp->next;
        }
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
                rear = Enqueue(&rear,&front, data);
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
