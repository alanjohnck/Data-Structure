#include<stdio.h>
#define MAX 10
int top=-1,stack[MAX],mintop=-1,minStack[MAX];

void push(int data){
    if(top==MAX-1){
        printf("STACK OVERFLOW");
    }

    else{
        top=top+1;
        stack[top]=data;
        printf("The pushed element is:%d\n",stack[top]);
        if(mintop==-1 || data<minStack[mintop]){
            minStack[++mintop]=data;
        }
    }
}

void pop(){
    int del;
    if(top==-1){
        printf("STACK UNDERFLOW");
    }
    else{
        del=stack[top];
        if(stack[top]==minStack[mintop]){
            minStack[mintop--];
        }
        printf("The popped element is:%d\n",del);
        top--;

    }
}

void getMin(){
    if(mintop==-1){
        printf("Stack is empty");
    }
    else{
        printf("%d\n",minStack[mintop]);
    }
}

void peek(){
    printf("The stack of top is:%d\n",stack[top]);
}

void display(){
    for(int i=top;i>=0;i--){
        printf("\n%d\n",stack[i]);
    }
}

int main(){

    int option,data;
    do{
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.Min Element\n");
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
            case 5:getMin();
                break;

        }

    }while(1);




}
