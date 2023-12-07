#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

char stack[MAX];
int top = -1;

void push(char data) {
    stack[++top] = data;
}

char pop() {
    char del = stack[top];
    stack[top--] = '\0';  // Corrected line to remove the element from the stack
    return del;
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else
        return false;
}

void isBalanced(char * data) {
    int flag = 0;
    int i = 0;
    while (data[flag] != '\0') {
        if (data[flag] == '(' || data[flag] == '[' || data[flag] == '{') {
            push(data[flag]);
        } else if (data[flag] == ')' || data[flag] == ']' || data[flag] == '}') {
            if (top == -1 || !isMatchingPair(pop(), data[flag])) {
                i = 1;
                break;  // Added break to exit the loop early if a mismatch is found
            }
        }
        flag++;
    }

    if (top == -1 && i == 0) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
}

int main() {
    printf("Enter the expression\n");
    char str[20];
    scanf("%s", str);  // Removed the unnecessary "&" before str
    isBalanced(str);

    return 0;  // Added a return statement for main
}
