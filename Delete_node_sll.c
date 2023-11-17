#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
node* temp;

// Function for inserting at the end
node* create_node(node* head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(node));
        head->data = data;
        head->next = NULL;
        temp = head;  // for getting the first address
    } else {
        node* newnode = malloc(sizeof(node));
        head->next = newnode;
        newnode->data = data;
        newnode->next = NULL;
        head = head->next;
    }
    return head;  // Return the head of the list
}

// Function for deleting a node with a given data value
node* Delete(node* head, int search) {
    if (head == NULL)
        return NULL;

    node* temp = head, *prev;

    if (temp != NULL && temp->data == search) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != search) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head;

    prev->next = temp->next;

    free(temp);

    return head;
}

int main() {
    int n, search;
    node* head = NULL;
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
    node* current = temp;  // Use the global temp pointer
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\nEnter the node to delete: ");
    head=temp;
    scanf("%d", &search);
    head = Delete(head, search);  // Update the head after deletion

    // Print the updated list
    printf("The updated list of numbers: ");
    node*updated = head;  // Use the updated head
    while (updated != NULL) {
        printf("%d ", updated->data);
        updated = updated->next;
    }

    return 0;
}
