#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * ppnext;
} node;

node *top = NULL;

node *push(node **top, int data) {
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
    return *top;
}

node *pop(node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
    } else {
        node *temp = *top;
        printf("Popped element is %d\n", (*top)->data);
        *top = (*top)->next;
        free(temp);
    }
    return *top;
}

void display(node **top) {

    if (*top == NULL) {
        printf("Stack is empty\n");
    } else {
        node *ptr = *top;
        printf("The elements in the stack\n");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int i, data;
    do {
        printf("1: Push\n2: Display\n3: Pop\n4: Exit\n");
        printf("Enter the operation\n");
        scanf("%d", &i);
        switch (i) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                top = push(&top, data);
                break;
            case 2:
                display(&top);
                break;
            case 3:
                top = pop(&top);
                break;
        }
    } while (i != 4);

    return 0;
}
