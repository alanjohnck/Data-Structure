#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}node;
node  * head =NULL;
node * Fhead = NULL;
node * Thead = NULL;
node * create_node(int data){
    node * newnode = malloc(sizeof (node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
node *  insert(node * head,int data){
    node * newnode = create_node(data);
    if(head==NULL){
        head = newnode;
    }else{
        node * temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return head;
}
void separate(node * pNode){
    node * newnode;
    node * temp=pNode;
    while(temp!=NULL) {
        if (pNode == NULL) {
            printf("list is empty\n");
        } else if (temp->data>0){
            newnode = create_node(temp->data);
            if(Fhead ==NULL){
                Fhead = newnode;
            }else{
                node * ptr = Fhead;
                while(ptr->next!=NULL){
                   ptr=ptr->next;
                }
                ptr->next = newnode;
                newnode->prev = ptr;
            }

        }else{
            newnode = create_node(temp->data);
            if(Thead==NULL){
                Thead = newnode;
            }else{
                node * ptr = Thead;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next = newnode;
                newnode->prev = ptr;
            }

        }
        temp = temp->next;

    }
}
void display(node * pNode){
    node * temp = pNode;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
int main(){
    int n,t,data;


    printf("Enter the first DLL\n");
    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient & exponent  %d:",i+1);
        scanf("%d",&data);
        head = insert(head,data);
    }
    display(head);
    separate(head);
    printf("Positive Numbers\n");
    display(Fhead);
    printf("Negative Numbers\n");
    display(Thead);

}