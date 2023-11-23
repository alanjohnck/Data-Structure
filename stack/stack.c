#include<stdio.h>
#define MAX 20

int top=-1,stack[MAX];
void push(int data){
    if(top==MAX-1){
        printf("STACK OVERFLOW");
    }
    else{
        top=top+1;
        stack[top]=data;
        printf("The pushed element is:%d\n",stack[top]);
    }
}

void pop(){
    int del;
    if(top==-1){
        printf("STACK UNDERFLOW");
    }
    else{
        del=stack[top];
        printf("The popped element is:%d\n",del);
        top--;
    }
}

void peek(){
    printf("The stack of top is:%d\n",stack[top]);
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");

    }
    else{
        for(int i=top;i>=0;i--){
            printf("\n%d\n",stack[i]);
        }
    }
}


int main(){

    int option,data;
    do{
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("Enter the operation\n");
        scanf("%d",&option);
        switch(option){
            case 1:printf("Enter number to push\n");
                scanf("%d",&data);
                push(data);
                break;
            case 2:pop();
                break;
            case 3:peek();
                break;
            case 4:display();
                break;

        }

    }while(1);


}