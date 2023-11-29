#include<stdio.h>
#include<stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Stack structure using singly linked list
typedef struct Stack {
    Node* top;
} Stack;

// Function to initialize a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to initialize an empty stack
Stack* initializeStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    int data = queue->front->data;
    Node* temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to reverse the content of a queue using a stack
void reverseQueue(Queue* queue) {
    Stack* stack = initializeStack();

    // Enqueue all elements into the stack
    while (!isQueueEmpty(queue)) {
        push(stack, dequeue(queue));
    }

    // Enqueue all elements back into the queue
    while (stack->top != NULL) {
        enqueue(queue, pop(stack));
    }

    free(stack);
}

// Function to display the elements of a queue
void displayQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* myQueue = initializeQueue();

    // Enqueue elements into the queue
    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);
    enqueue(myQueue, 4);
    enqueue(myQueue, 5);

    printf("Original Queue: ");
    displayQueue(myQueue);

    // Reverse the content of the queue
    reverseQueue(myQueue);

    printf("Reversed Queue: ");
    displayQueue(myQueue);

    // Clean up
    while (!isQueueEmpty(myQueue)) {
        dequeue(myQueue);
    }
    free(myQueue);

    return 0;
}
