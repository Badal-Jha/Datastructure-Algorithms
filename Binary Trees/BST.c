#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *left;
        struct Node *right;

};
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct Node *root=malloc(sizeof(struct Node));
    root->data=10;
    root->left=malloc(sizeof(struct Node));
    root->left->data=12;
    root->right=malloc(sizeof(struct Node));
    root->right->data=10;
    root->left->left=malloc(sizeof(struct Node));
    root->left->left->data=4;
    root->left->right=malloc(sizeof(struct Node));
    root->left->right->data=7;
    root->right->right=malloc(sizeof(struct Node));
     root->right->right->data=11;
    preorder(root);
    return 0;
    
}