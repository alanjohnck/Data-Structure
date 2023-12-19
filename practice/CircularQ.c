#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int rear= -1,front =-1;
int Q[MAX];
void Enqueue(int data){
    if( front == (rear+1)% MAX ){
        printf("Q is full\n");
    }else if(rear==-1){
        front = rear =0;
        Q[rear] =data;
    }else{
        rear=(rear+1)%MAX;
        Q[rear]=data;
    }
}
void Deqeue(){
    if(front == -1){
        printf("Stack is Empty\n");
    }else if(front==rear){
        printf("The popped element is %d:",Q[front]);
        front=rear=-1;
    }else{
        printf("The popped element is %d;",Q[front]);
        front = (front+1)%MAX;
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }else{
        int i=front;
        do{
            printf("%d\t",Q[i]);
            i=(i+1)%MAX;
        }while(i!=(rear+1)%MAX);
    }
}
int main(){

    int item;
    int choice;
    int i;
    do{
        printf("\nEnter 1 to enqeue, 2 to deqeue, 3 to displayQ\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the item:");
                scanf("%d",&item);
               Enqueue(item);
                break;
            case 2:Deqeue();
                break;
            case 3:display();
                break;
        }
    } while(choice!=0);

    return 0;

}