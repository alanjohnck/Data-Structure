#include <stdio.h>
#define MAX 10
int front=-1,rear=-1;
void enque(int Q[MAX],int item){
    if(rear==MAX-1){
        printf("Queue is full");
    }else if(rear==-1){
        front=rear=0;
        Q[rear]=item;
    }else{
        rear++;
        Q[rear]=item;
    }
}

void deque(int Q[MAX]){
    if(front==-1){
        printf("Queue is empty");
    }else if(front==rear){
        printf("The popped element is %d\n",Q[front]);
        front=rear=-1;
    }else{
        printf("The popped element is %d\n",Q[front]);
        front=front+1;
    }
}
void displayQ(int Q[MAX]){
    if(front==-1){
        printf("stack is empty\n");
    }else{
        printf("The elements in the queue\n");
        for(int i=front;i<=rear;i++){

            printf("%d\t",Q[i]);
        }
    }
}
int main()
{
    int Q[MAX];
    int item;
    int choice;
    int i;
    do{
        printf("\nEnter 1 to enqeue, 2 to deqeue, 3 to displayQ\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the item:");
                scanf("%d",&item);
                enque(Q,item);
                break;
            case 2:deque(Q);
                break;
            case 3:displayQ(Q);
                break;
        }
    } while(choice!=0);

    return 0;
}