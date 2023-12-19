#include<stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    int del = stack[top];
    stack[top--] ;
    return del;
}

void decTohex(int dec) {
    int hex;
    while (dec != 0) {
        hex = dec % 2;
        push(hex);
        dec = dec / 2;
    }
    printf("Hexadecimal representation: ");
    while (top != -1) {
        printf("%d", pop()); // Use %X to print in hexadecimal format
    }
    printf("\n");
}

int main() {
    printf("Enter the decimal number\n");
    int dec;
    scanf("%d", &dec);
    decTohex(dec);
    return 0;
}
