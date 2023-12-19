#include <stdio.h>
#include <stdlib.h>
#define max 10

int Q1[max], Q2[max];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
int count = 0;

void Enqueue1(int data) {
    rear1 = rear1 + 1;
    Q1[rear1] = data;
}

int Dequeue1() {
    front1 = front1 + 1;
    return Q1[front1];
}

void Enqueue2(int data) {
    rear2 = rear2 + 1;
    Q2[rear2] = data;
}

int Dequeue2() {
    front2 = front2 + 1;
    return Q2[front2];
}

void Push(int data) {
    Enqueue1(data);
    count++;
    int a;
    while (count > 0) {
        Enqueue2(Dequeue1());
        count--;
    }
}

void Pop() {
    if (front2 == rear2) {
        printf("Stack is empty\n");
        return;
    }
    printf("Deleted element is: %d\n", Dequeue2());
}

int main() {
    int i;
    int data;

    do {
        printf("Enter the option (1: Push, 2: Pop, 0: Exit): ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                Push(data);
                break;
            case 2:
                Pop();
                break;
        }
    } while (i != 0);

    return 0;
}
