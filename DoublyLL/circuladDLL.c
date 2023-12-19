#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

node *create_node(int data) {
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insert_at_beginning(int data) {
    node *newnode = create_node(data);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_at_end(int data){
    node *newnode = create_node(data);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insert_at_position(int data, int position) {
    node *newnode = create_node(data);
    node *temp = head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    if (temp == head) {
        insert_at_beginning(data);
    } else if (temp == tail) {
        insert_at_end(data);
    } else {
        newnode->next = temp;
        newnode->prev = temp->prev;
        temp->prev->next = newnode;
        temp->prev = newnode;
    }
}

void printList() {
    node *temp = head;
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n, data, choice, position;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data %d:", i + 1);
        scanf("%d", &data);
        insert_at_end(data);
    }
    printList();
    printf("Enter 1 to insert at beginning, 2 to insert at end, 3 to insert at position, 4 to print list: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the data for the new node: ");
            scanf("%d", &data);
            insert_at_beginning(data);
            break;
        case 2:
            printf("Enter the data for the new node: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;
        case 3:
            printf("Enter the position where you want to insert new node: ");
            scanf("%d", &position);
            printf("Enter the data for the new node: ");
            scanf("%d", &data);
            insert_at_position(data, position);
            break;
        case 4:
            printList();
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
