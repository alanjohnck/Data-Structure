#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));


    new_node->data = new_data;


    new_node->next = NULL;


    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }


    last->next = new_node;
    return;
}
void printList(struct Node*node){
    while(node!=NULL){
        printf("%d ->",node->data);
        node=node->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;
    int i,size,item;
    printf("Enter the size:\n");
    scanf("%d",&size);
    for(i=0;i<size;i++) {
        printf("Enter the element %d:", i + 1);
        scanf("%d", &item);
        insertAtEnd(&head, item);
    }
    printf("the linked list is:\n");
    printList(head);

    return 0;
}
