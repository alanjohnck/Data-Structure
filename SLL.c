#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
node* temp;
node*  create_node(node* head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(node));
        head->data = data;
        head->next = NULL;
        temp = head;  //for getting first address
    } else {
        node* newnode = malloc(sizeof(node));
        head->next = newnode;
        newnode->data = data;
        newnode->next = NULL;
        head = head->next;
    }
    return head;
}

int main() {
    int n;
    node *head = NULL;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data of %d node: ", i + 1);
        scanf("%d", &data);
        head = create_node(head, data);
    }

    // Print the list of numbers

    printf("The list of numbers: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
