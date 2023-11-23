#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;
void append(Node** head, int item)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = item;
    new_node->next = NULL;

    Node* ptr = *head;

    if( *head == NULL ){
        *head = new_node;
        return;
    }

    while( ptr->next != NULL ){
        ptr = ptr->next;
    }

    ptr->next = new_node;
    return;
}

void printList(Node * node)
{
    while(node != NULL)
    {
        printf("%d -> " , node->data);
        node = node ->next;
    }
    printf("NULL");
    printf("\n");
}

void add_at_pos( Node** head , int data , int pos)
{
    Node* ptr = *head;
    Node* ptr2 = (Node* ) malloc(sizeof(Node));

    ptr2->data = data;
    ptr2->next = NULL;

    pos--;

    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }

    ptr2->next = ptr ->next;
    ptr ->next = ptr2;
}

int main()
{
    Node* head = NULL;
    int i , data , pos,n,element;
    printf("Enter the number of nodes:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the node %d:",i+1);
        scanf("%d",&element);
        append(&head,element);
    }
    printf("the original Linked list is:\n");
    printList(head);
    printf("\n");

    printf("Enter the position to be added at : ");
    scanf("%d", &pos);

    printf("Enter the element to be added : ");
    scanf("%d", &data);

    add_at_pos(&head , data , pos);

    printf("the Linked list after addition is:\n");
    printList(head);
    printf("\n");

}
