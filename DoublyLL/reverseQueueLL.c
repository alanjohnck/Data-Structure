#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to initialize a stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, struct Stack* stack, int data) {
    // Create a new node
    struct Node* newNode = createNode(data);

    // If the queue is empty, set the front and rear to the new node
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear of the queue
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    // Push the element onto the stack
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue, struct Stack* stack) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    // Pop the element from the stack
    struct Node* poppedNode = stack->top;
    stack->top = poppedNode->next;

    int dequeuedValue = poppedNode->data;

    // Remove the front element from the queue
    struct Node* frontNode = queue->front;
    queue->front = frontNode->next;

    // If the queue becomes empty, update the rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    // Free the memory of the dequeued node
    free(frontNode);

    // Display the stack after dequeue operation
    printf("Stack after dequeue: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return dequeuedValue;
}

int main() {
    struct Queue queue;
    struct Stack stack;
    initializeQueue(&queue);
    initializeStack(&stack);

    // Enqueue elements into the queue and store them in the stack
    enqueue(&queue, &stack, 1);
    enqueue(&queue, &stack, 2);
    enqueue(&queue, &stack, 3);

    // Display the stack after enqueue operations
    printf("Stack after enqueue: ");
    struct Node* current = stack.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Dequeue an element and display the stack
    int dequeuedValue = dequeue(&queue, &stack);
    printf("Dequeued value: %d\n", dequeuedValue);

    // Dequeue another element and display the stack
    dequeue(&queue, &stack);

    return 0;
}
