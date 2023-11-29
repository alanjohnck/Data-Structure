#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Node structure for doubly linked list
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;
// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
Node* insertEnd(Node* head, char data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        Node * temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

// Function to check if a doubly linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == NULL) {
        return true; // An empty list is a palindrome
    }

    Node* start = head;
    Node* end = head;

    // Move 'end' to the last node
    while (end->next != NULL) {
        end = end->next;
    }

    while (start != end && start->prev != end) {
        if (start->data != end->data) {
            return false;
            // Characters at symmetric positions are not equal
        }
        start = start->next;
        end = end->prev;
    }

    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    Node* head = NULL;
    for (int i = 0; i < strlen(str); i++) {
        head = insertEnd(head, str[i]);
    }
    if (isPalindrome(head)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
