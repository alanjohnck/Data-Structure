#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coeff;
    int expo;
    struct node*next;
}node;
node * poly1=NULL,*poly2=NULL;

node * readPoly(node **poly,int p){
    int coeff,expo;

    for(int i=0;i<p;i++){
        printf("Enter the coeff and expo:");
        scanf("%d%d",&coeff,&expo);
        node * newnode = malloc(sizeof (node));
        newnode->coeff=coeff;
        newnode->expo = expo;
        newnode->next = *poly;
        *poly =newnode;
    }
    return  *poly;
}
void displayPoly(node**poly){
    node *temp = *poly;

        while(temp!=NULL){
            printf("%d|%d->",(temp)->coeff,(temp)->expo);
            temp =temp ->next;
        }

}
node  * PolyAddition(){


}


int main(){
    int p1,p2;
    printf("Enter the number of terms in first Polynomial:");
    scanf("%d",&p1);
    readPoly(&poly1,p1);
    displayPoly(&poly1);
    printf("Enter the number of terms in second polynomial:");
    scanf("%d",&p2);
    readPoly(&poly2,p2);
    displayPoly(&poly2);

}