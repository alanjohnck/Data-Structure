#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* head = NULL;
node* Fhead = NULL;
node* Thead = NULL;

node* create_node(node* head, int data) {
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return head;
}

void printList() {
    while (Fhead != NULL) {
        printf("%d\t", Fhead->data);
        Fhead = Fhead->next;
    }
    node * temp =Thead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->prev;
    }
}


int main() {
    int n, data;
    printf("Enter the no.of nodes in the first DLL\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d:", i + 1);
        scanf("%d", &data);
        Fhead = create_node(Fhead, data);
    }

    printf("Enter the no.of nodes in the second DLL\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d:", i + 1);
        scanf("%d", &data);
        Thead = create_node(Thead, data);
    }
    printf("The reversed list\n");
    printList();
    return 0;
}
