#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;

}node;

node* Fhead = NULL;
node* Thead = NULL;
node * insert(node * head,int data){
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;

    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;

    }
    return head;
}

node * new=NULL;
void printIntersection(){
    node * temp1=Fhead;
    node * temp2=Thead;

    while(temp1!=NULL){
        temp2=Thead;
        while (temp2!=NULL){
            if(temp1->data==temp2->data){
                node * newnode = malloc(sizeof (node));
                newnode->data = temp1->data;
                newnode->next =NULL;
                if(new==NULL){
                    new=newnode;
                }else{
                    node * temp = new;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next= newnode;
                }
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    printf("Intersection\n");
    while(new!=NULL){
        printf("%d\t",new->data);
        new=new->next;
    }
}

int main(){
    int n, data;
    printf("Enter the no.of nodes in the first DLL\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d:", i + 1);
        scanf("%d", &data);
        Fhead = insert(Fhead, data);
    }

    printf("Enter the no.of nodes in the second DLL\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d:", i + 1);
        scanf("%d", &data);
        Thead = insert(Thead, data);
    }
    printIntersection();
}
