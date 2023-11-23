
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
} Node;


void append(Node** head, int item)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = item;
    new_node->next = NULL;

    Node* ptr = *head;

    if( *head == NULL )
    {
        *head = new_node;
        return;
    }

    while( ptr->next != NULL )
    {
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

void getmin(Node** head)
{
    Node* temp = *head;

    if( temp == NULL)
    {
        printf("Empty list");
    }

    int min = temp->data;
    while( temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp-> data;
        }
        temp = temp -> next;
    }

    printf("The smallest element in the list is: %d \n" , min);

}

int main()
{
    Node* head = NULL;
    int i , item , search,n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the %d node:",i+1);
        scanf("%d",&item);
        append(&head,item);
    }
    printf("the original Linked list is:\n");
    printList(head);
    printf("\n");

    getmin(&head);


}
