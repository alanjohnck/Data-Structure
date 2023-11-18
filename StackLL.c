#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* top = NULL;

node* push(node* top, int data){
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
    return top;
}

void pop(node** top){
    node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

void peek(){
    if(top != NULL){
        printf("The peek element is: %d", top->data);
    } else {
        printf("The stack is empty");
    }
}

int main(){
    int i, data;
    do{
        printf("1:push\n2:peek\n3:pop\n");
        scanf("%d", &i);

        switch(i){
            case 1: printf("Enter the data to push: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            case 2: peek();
                break;
            case 3: if(top != NULL){
                    pop(&top);
                } else {
                    printf("The stack is empty");
                }
                break;
        }
    } while(i != 4);
    return 0;
}
