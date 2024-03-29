#include<stdio.h>
#include<stdbool.h>
#define  Max_size 100
int stack[Max_size],tempstack[Max_size];
int top=-1,temp_top=-1,temp;
bool stack_is_empty(){
    if(top==-1)
        return true;
    else
        return false;
}
bool temp_is_empty() {
    if (temp_top == -1)
        return true;
    else
        return false;
}
void stack_pop(){
    stack[top--];
}
void temp_stack_pop(){
    tempstack[temp_top--];
}

void stack_push(int element){
    stack[++top]=element;
}

void tempstack_push(int element){
    tempstack[++temp_top]=element;
}

void sort(){
    while(!(stack_is_empty())){
        temp=stack[top];
        stack_pop();
        while(!(temp_is_empty()) && tempstack[temp_top]>temp){
            stack_push(tempstack[temp_top]);
            temp_stack_pop();
        }
        tempstack_push(temp);
    }
    printf("\nSorted Stack:\n");
    for(int i=0;i<=temp_top;i++){
        printf("%d\n",tempstack[i]);
    }
}

int main(){

    int n,i,x;

    printf("Enter number of terms in stack:");

    scanf("%d",&n);

    printf("\nEnter elements:");

    for(i=0;i<n;i++){
        scanf("%d",&x);
        stack_push(x);
    }
    sort();
    return 0;

}


