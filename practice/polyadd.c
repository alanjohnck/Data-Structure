#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int coeff;
    int expo;
    struct node * next;
}node;
node * create_node(int expo,int coeff){
    node * newnode = malloc(sizeof (node));
    newnode -> expo = expo;
    newnode ->coeff = coeff;
    newnode ->next  = NULL;
    return newnode;
}


node  * readPoly(node * head,int expo,int coeff){

    node * newnode = create_node(expo,coeff);
    if(head ==NULL){
        head = newnode;

    }else{
        node  * temp=head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
void display(node * head){
    node * temp = head;
    while(temp->next!=NULL){
        printf("%d^%d+",temp->coeff,temp->expo);
        temp=temp->next;
    }
    printf("%d^%d",temp->coeff,temp->expo);
    printf("\n");
}
node * polyAdd(node * Fhead, node * Thead) {
    node * temp1 = Fhead;
    node * temp2 = Thead;
    node * newnode;
    node * Rhead = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->expo == temp2->expo) {
            newnode = create_node(temp1->expo, temp1->coeff + temp2->coeff);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->expo > temp2->expo) {
            newnode = create_node(temp1->expo, temp1->coeff);
            temp1 = temp1->next;
        } else {
            newnode = create_node(temp2->expo, temp2->coeff);
            temp2 = temp2->next;
        }

        if (Rhead == NULL) {
            Rhead = newnode;
        } else {
            node * temp = Rhead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    while (temp1 != NULL) {
        newnode = create_node(temp1->expo, temp1->coeff);
        temp1 = temp1->next;
        if (Rhead == NULL) {
            Rhead = newnode;
        } else {
            node * temp = Rhead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    while (temp2 != NULL) {
        newnode = create_node(temp2->expo, temp2->coeff);
        temp2 = temp2->next;
        if (Rhead == NULL) {
            Rhead = newnode;
        } else {
            node * temp = Rhead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    return Rhead;
}

int main(){
    int n,t,expo,coeff;
    node * Fhead=NULL;
    node * Thead=NULL;

    printf("Enter the first polynomial\n");
    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient & exponent  %d:",i+1);
        scanf("%d %d",&coeff,&expo);
        Fhead = readPoly(Fhead,expo,coeff);
    }
    display(Fhead);
    printf("Enter the second polynomial\n");
    printf("Enter the number of terms in the second polynomial\n");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter the coefficient & exponent  %d:",i+1);
        scanf("%d %d",&coeff,&expo);
        Thead = readPoly(Thead,expo,coeff);
    }
    display(Thead);
    printf("The sum of the polynomials\n");
    node * Rhead = polyAdd(Fhead,Thead);
    display(Rhead);


}