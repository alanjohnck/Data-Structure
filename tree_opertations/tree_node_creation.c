#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    int data;
    struct treenode * left;
    struct treenode * right;
}treenode;

treenode * create_treenode(int data){

    treenode * result = malloc(sizeof (treenode));
    if(result!=NULL){
        result->left=NULL;
        result->right=NULL;
        result->data=data;
    }
    return result;
};

void preorder(treenode * root){
    if(root==NULL){
        return ;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);

}
void postorder(treenode * root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);

}
void inorder(treenode * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

int main(){

    treenode * n1=create_treenode(10);
    treenode * n2=create_treenode(11);
    treenode * n3=create_treenode(12);
    n1->left=n2;
    n1->right=n3;
    postorder(n1);



}
