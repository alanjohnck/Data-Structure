#include <stdio.h>

#define MAX 5
int front=-1,rear=-1;

void enque(int Q[MAX],int item){
    if(front==(rear+1)%MAX){
        printf("Queue is full\n");
    }else if(rear==-1){
        front=rear=0;
        Q[rear]=item;
    }else{
        rear=(rear+1)%MAX;
        Q[rear]=item;
    }
}

void deque(int Q[MAX]){
    if(front==-1){
        printf("stack is empty");
    }else if(front==rear){
        printf("The popped element is %d\n",Q[front]);
        front=rear=-1;
    }else{
        printf("The popped element is %d\n",Q[front]);
        front=(front+1)%MAX;
    }
}

void displayQ(int Q[MAX]) {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The elements in the queue\n");
        int i = front;
        do {
            printf("%d\t", Q[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
    }
}

int main() {
    int Q[MAX];
    int item;
    int choice;
    int i;

    do{
        printf("\nEnter 1 to enque, 2 to deque, 3 to displayQ\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the item:");
                scanf("%d",&item);
                enque(Q,item);
                break;
            case 2:
                deque(Q);
                break;
            case 3:
                displayQ(Q);
                break;
        }
    } while(choice!=0);

    return 0;
}

