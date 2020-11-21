#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node* right;
};



struct Node *insertBST(struct Node *root,int x)
{  root==NULL;
    if(root==NULL)
    {
          root=(struct Node*)malloc(sizeof(struct Node));
          root->data=x;
          root->left=NULL;// It is important to make left and right child of leaf node as NULL
          root->right=NULL;
          
       
          return root;
    }
       
    else if(root->data>x)
    root->left=insertBST(root->left,x);
    else if(root->data<x)
    {
       root->right=insertBST(root->right,x);
    }
  
    return root;
}
//To find inorder successor
struct Node *getSuccesor(struct Node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
    curr=curr->left;
    return curr;
}

//deletion in binery search tree
struct Node *deletNode(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data > key)
    {
        root->left = deletNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deletNode(root->right, key);
    }
    else
    {
        if (root->right == NULL)
        {
           struct  Node *temp = root->left;
           free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            struct Node *succ=getSuccesor(root);
            root->data=succ->data;
            root->right=deletNode(root->right,succ->data);
        }
    }
    return root;
}
int heightNode(struct Node *root)
{   if(root==NULL)return 0;
    int h1=heightNode(root->left);
    int h2=heightNode(root->right);
    return h1>h2?h1+1:h2+1;
}
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
    struct Node *root=NULL;
    printf("data before deletion: ");
    root=insertBST(root,10);
 
    root=insertBST(root,5);
 
    root=insertBST(root,15);
    root=insertBST(root,12);
    root=insertBST(root,18);
    root=insertBST(root,20);
    root=insertBST(root,25);
    
    preorder(root);
      printf("\nHeight of tree: %d",heightNode(root));
    printf("\nDeletion...\n");
    deletNode(root,15);
    printf("data after deletion: ");
     preorder(root);
 
    return 0;
}
