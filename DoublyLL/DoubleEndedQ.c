#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty deque
Deque* initializeDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isDequeEmpty(Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to delete an element from the front of the deque
int deleteFront(Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE);
    }

    int data = deque->front->data;
    Node* temp = deque->front;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

// Function to delete an element from the rear of the deque
int deleteRear(Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE);
    }

    int data = deque->rear->data;
    Node* temp = deque->rear;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

// Function to display the elements of the deque
void displayDeque(Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    Node* current = deque->front;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque* myDeque = initializeDeque();

    // Insert elements at the front
    insertFront(myDeque, 1);
    insertFront(myDeque, 2);
    insertFront(myDeque, 3);

    // Insert elements at the rear
    insertRear(myDeque, 4);
    insertRear(myDeque, 5);

    printf("Deque after insertions: ");
    displayDeque(myDeque);

    // Delete elements from the front and rear
    int frontElement = deleteFront(myDeque);
    int rearElement = deleteRear(myDeque);

    printf("Deleted front element: %d\n", frontElement);
    printf("Deleted rear element: %d\n", rearElement);

    printf("Deque after deletions: ");
    displayDeque(myDeque);

    // Clean up
    while (!isDequeEmpty(myDeque)) {
        deleteFront(myDeque);
    }
    free(myDeque);

    return 0;
}
