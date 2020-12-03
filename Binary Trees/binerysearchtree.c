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
         return  temp;
        }
        else
        {
            struct Node *succ=getSuccesor(root);
            root->data=succ->data;
          root->right=deletNode(root->right,succ->data);
        }
    }
 //   return root;
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
    printf("enter 0:to do nothing, 1:to insert, 2:delete ,3:print data\n\n");
  
    while(1)
    {   int t;
      printf("\nenter key(0,1,2,3): ");
         scanf("%d",&t);
    	if(t==0)
    	break;
    	else if(t==1)
    	{   printf("\nenter data to insert: ");
    		int x;
    		scanf("%d",&x);
    		root=insertBST(root,x);
		}
		else if (t==2)
		{   printf("\nenter data to delete: ");
			int key;
			scanf("%d",&key);
	      root= deletNode(root,key);
		}
    	else if(t==3)
    	{   printf("\n\nElements present in BST is: ");
    		preorder(root);
		}
	}
 
    return 0;
}
