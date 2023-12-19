#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;
node * head=NULL;
void insert(int data){
    node * newnode = malloc(sizeof (node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL)
    {
       head=newnode;
    }else{
        node * temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
}
void search_ll_del(int search){
    node * temp =head;
    node * prev=NULL;
    if(temp!=NULL && temp->data==search){
       head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL  && temp->data!=search){
         prev=temp;
         temp=temp->next;
    }
    node * del = temp;
    prev->next = temp->next;
    free(del);
}
//void delete_pos(int pos){
//    node * ptr=head;
//    node * prev;
//    if(pos==1){
//        node * temp = head;
//        head=head->next;
//        free(temp);
//    }else{
//        for(int i =1;i<pos;i++){
//            prev = ptr;
//            ptr=ptr->next;
//        }
//        node * delete = ptr;
//        prev->next = ptr->next;
//        free(ptr);
//    }
//}
int main(){
    int n,data,pos,search;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        printf("Enter the node %d :",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("Enter the search element to delete:\n");
    scanf("%d",&search);
    search_ll_del(search);

//    scanf("%d",&pos);
//    delete_pos(pos);
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }

}


