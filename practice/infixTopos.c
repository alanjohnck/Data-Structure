#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 10

int top = -1;
char stack[MAX];

void push(char data) {
    if (top == MAX - 1) {
        printf("stack is full\n");
    } else {
        top = top + 1;
        stack[top] = data;
    }
}

char pop() {
    char del;
    if (top == -1) {
         printf("stack is empty\n");
        return '\0'; // Return a default value, since the stack is empty
    } else {
        del = stack[top];
        top--;
    }
    return del;
}

void output(char x) {
    printf("%c", x);
}

bool isOperand(char ch) {
    return isalnum(ch); // Using isalnum from ctype.h to check if the character is an alphanumeric character
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

void toPostfix(char * expression) {
    push('#');
    for (int i =  0 ; expression [i] != '\0' ; i++) {
        char item = expression [i];
        if (isOperand(item)) {
            output(item);
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (stack[top] != '(') {
                output(pop());
            }
            pop(); // Pop '('
        } else {
            while (precedence(stack[top]) >= precedence(item)) {
                output(pop());
            }
            push(item);
        }
    }

    while (stack[top] != '#') {
        output(pop());
    }
}

int main() {
    char str[20];
    printf("Enter the expression\n");
    scanf("%s", str);
    toPostfix(str);

    return 0;
}
