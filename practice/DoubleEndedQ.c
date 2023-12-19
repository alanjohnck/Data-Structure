//double linked list-deque,sinle linked list-deque,priority queue,ciruclar queue,polynomial addition,sparse addition

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}node;
node * head =NULL;
node * create_node(int data){
    node * newnode = malloc(sizeof (node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert_end(int data){
  node * newnode = create_node(data);
  if(head==NULL){
      head= newnode;
  }else{
      node * temp = head;
      while(temp->next!=NULL){
          temp=temp->next;
      }
      temp->next = newnode;
      newnode->prev = temp;
  }
}
void insert_front(int data){
    node * newnode = create_node(data);
   if(head==NULL){
       head=newnode;
   }else{
        newnode->next =head;
        head->prev = newnode;
        head = newnode;
   }
}
void delete_front(){
    if(head==NULL){
        printf("Queue is empty");
    }else{
        node * temp = head;
        printf("The deleted element is %d:",temp->data);
        head=head->next;
        head->prev =NULL;
        free(temp);
    }
 }
void delete_rear(){
    node * temp ;
    if(head==NULL){
        printf("Queue is empty");
    }else{
        node * temp =head;
        node * prev;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        printf("The deleted element is %d:",temp->data);
        prev->next = NULL;
        free(temp);
    }
}

void display(){
    node * temp = head;
    if(head==NULL){
        printf("Queue is empty");
    }
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void inset_at_any(int pos,int data){
    node * newnode = create_node(data);
    if(pos==1){
        insert_front(data);
    }else if(pos>1)
    {
        node * temp=head;
        for(int i=0;i<pos-2;i++){
            temp=temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }else{
        insert_end(data);
    }
}
int main(){
    int i, data,pos;
    do {
        printf("\n1: insert_rear\n2: insert_front\n3: delete_rear\n4: delete_front\n5.display\n6.insert_at_any\n");
        printf("Enter the operation\n");
        scanf("%d", &i);
        switch (i) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 2:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                insert_front(data);
                break;
            case 3:
                delete_rear();
                break;
            case 4:delete_front();
                break;
            case 5:display();
                break;
            case 6:
                printf("Enter position and data\n");
                scanf("%d",&pos);
                scanf("%d",&data);
                inset_at_any(pos,data);
        }
    } while (i != 10);


}