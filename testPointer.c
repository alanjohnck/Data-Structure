#include<stdio.h>


typedef struct node{
    int data;
    struct node * next;
}node;
int * func(int *ptr){
    int *temp =4;
    printf("hwllo%p\n",ptr);
    ptr = &temp;

    return ptr;

}
int main(){
    int *ptr1,*ptr2;
    int a=1;
    int b= 3;
    ptr1=&a;
    printf("address of a:%p\n",&a);
    printf("hai%p\n",ptr1);
    printf("address of ptr%p\n",&ptr1);
    ptr1 = func(ptr1);
    printf("hai%p",ptr1);



}