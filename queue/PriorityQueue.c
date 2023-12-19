
#include<stdio.h>
#include<stdlib.h>
int front,rear,size;
#define MAX 10
typedef struct {
    int item;
    int priority;

}priorityQ;
 priorityQ  Q[MAX];
void display(){
    int i;
    if(front==-1){
        printf("Queue is empty\n");

    }else{
        for(i =front;i<=rear;i++){
            printf("%d\t",Q[i].item);
        }
    }
}
void enqueue(int item , int priority){
    int i,loc;
    if(front==0 && rear==MAX-1){
        printf("Queue is full\n");
    }else if(front==-1){
        front=0;
        rear=0;
        Q[rear].item = item;
        Q[rear].priority =priority;
    }
    else{
        if(rear==MAX-1){
             for(i=front;i<=rear;i++){
                 Q[i-1]=Q[i];
             }
             front--;
             rear--;
        }
        for(i=rear;i>=front;i--){
            if(Q[i].priority < priority){
                break;
            }
        }
        loc = i+1;
        for(i=rear;i>=loc;i--){
            Q[i+1]=Q[i];
        }
        Q[loc].item=item;
        Q[loc].priority = priority;
        rear++;
    }
}
void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
    }else if(front==rear){
        printf("deleted item is %d",Q[front].item);
        front=-1;
        rear = -1;
    }else{
        printf("deleted item is %d",Q[front].item);
        front++;
    }
}
int main(){
    int option,item,priority;
     front=-1;
     rear=-1;

     do{
         printf("\n1.Enqueue\n2.dequeue\n3.display");
         printf("\nEnter the options:\n");
         scanf("%d",&option);
         switch (option) {
             case 1:
                 printf("Enter the item and priority\n");
                 scanf("%d%d",&item,&priority);
                 enqueue(item,priority);
                 break;
             case 2 :dequeue();
                     break;
             case 3 :display();
                      break;
         }

     }while(option!=4);
}



