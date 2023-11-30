
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;
node* head = NULL;

void insert(node ** head, int data)
{
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head == NULL) {
        *head = newnode;
        (*head)->next = *head;  // Circular link to itself
        (*head)->prev = *head;  // Circular link to itself
    }
    else {
        node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = *head;     //  Circular link to the first node
        (*head)->prev = newnode;  //  Circular link from the first node to the last node
    }

}
void traverse(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = head;
    do {
        printf("%d\t", current->data);
        current = current->next;
    } while (current != head);
    printf("%d",current->data);
}

int main() {

    int n, data;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the %d node:", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }
    printf("The nodes are:\n");
    traverse(head);
    return 0;

}
