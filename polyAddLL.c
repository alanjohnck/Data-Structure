#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coeff;
    int expo;
    struct node*next;
}node;

node * Qhead,*Phead,*Rhead;
node * ReadPoly(){
      node * new,*ptr,*head=NULL;
      int n,i;
      printf("\nEnter the total number of terms in the polynomial:");
      scanf("%d",&n);
      printf("Enter the coefficient and exponent of the polynomial:");
      for(int i=1;i<=n;i++){
        printf("Enter(coef%d,expo%d)",i,i);
        new= malloc(sizeof (node));
        scanf("%d",&new->coeff);
        scanf("%d",&new->expo);
        new -> next=NULL;
        if(head==NULL){
            head = new;
            ptr = head;
        }else{
            ptr ->next = new;
            ptr =new;
        }
    }
    return head;
}
void DisplayPoly(node *head){
    node * ptr;
    if(head==NULL){
        printf("Polynomial is Empty");
    }else{
        ptr = head;
        while(ptr ->next !=NULL){
            printf("%dx^%d+",ptr->coeff,ptr->expo);
            ptr=ptr->next;
        }
        printf("%dx^%d\t",ptr->coeff,ptr->expo);
    }
}
node  * PolyAddition(){
      node * new,*P,*Q,*R,*head = NULL;
      P=Phead;
      Q=Qhead;
      while(P!=NULL&&Q!=NULL) {
          if (P->expo == Q->expo) {
              new = malloc(sizeof(node));
              new->coeff = P->coeff + Q->coeff;
              new->expo = P->expo;
              new->next = NULL;
              P = P->next;
              Q = Q->next;
          } else if (P->expo > Q->expo) {
              new = malloc(sizeof(node));
              new->coeff = P->coeff;
              new->expo = P->expo;
              new->next = NULL;
              P = P->next;
          } else {
              new = malloc(sizeof(node));
              new->coeff = Q->coeff;
              new->expo = Q->expo;
              new->next = NULL;
              Q = Q->next;
          }
          if (head == NULL) {
              head = new;
              R = head;
          } else {
              R->next = new;
              R = new;
          }
      }
          while(P!=NULL){
              new= malloc(sizeof (node));
              new->coeff=P->coeff;
              new->expo=new->expo;
              new->next=NULL;
              if(head==NULL){
                  head=new;
                  R=head;
              }
              else{
                  R->next=new;
                  R=new;
              }
              P=P->next;
          }
          while(Q!=NULL){
              new= malloc(sizeof (node));
              new->coeff=Q->coeff;
              new->expo=Q->expo;
              new->next=NULL;
              if(head==NULL){
                  head=new;
                  R=head;
              }else{
                  R->next=new;
                  R=new;
              }
              Q=Q->next;
          }

    return head;

}

int main(){
    printf("\nEnter the details of First polynomial:");
    Phead=ReadPoly();
    printf("\nEnter the details of Second polynomial:");
    Qhead=ReadPoly();
    printf("\nFirst polynomial :");
    DisplayPoly(Phead);
    printf("Second polynomial :");
    DisplayPoly(Qhead);
    Rhead = PolyAddition();
    printf("Result of the addition");
    DisplayPoly(Rhead);

}