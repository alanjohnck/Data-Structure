#include<stdio.h>
#include<stdbool.h>
#include <ctype.h>
#define MAX 10

int stack[MAX];
int top =- 1;

void push(int data)
{
    if(top==MAX-1){
        printf("Stack is full\n");
    }else {
        stack[++top] = data;
    }
}

int pop(){
    int del;
    if(top==-1){
        printf("stack is empty\n");
    }else{
         del=stack[top--];

    }
    return del;
}
bool is_operator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
    {
        return true;
    }
    return false;
}
void checkOperator(char symbol){
    int operand1 ;
    int operand2 ;
    int result;
    if(symbol!='\0') {
        if (isdigit(symbol)) {
            push(symbol-'0');
        } else {
            int operand2 = pop();
            int operand1 = pop();

            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    push(result);
                    break;
                case '-':
                    result = operand1 - operand2;
                    push(result);
                    break;
                case '*':
                    result = operand1 * operand2;
                    push(result);
                    break;
                case '/':
                    result = operand1 / operand2;
                    push(result);
                    break;

            }

        }
    }

}
int main(){
    char str[20];
    int result;
    printf("Enter the expression:");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
       checkOperator(str[i]);
    }
    printf("sum:%d",stack[top]);
}