#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    int height;
    struct Node *left ,*right;
}*root=NULL;
int NodeHeight(struct Node *p)
{
    int hl,hr;
    if(p==NULL)return 0;
    hl=NodeHeight(p->left);
    hr=NodeHeight(p->right);
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct Node *p)
{
    if(p==NULL || p->left || p->right)return 0;
    
    int hl,hr;
    hl=p->left->height;
    hr=p->right->height;
   /* hl=p&&p->left?p->left->height:0;
    hr=p&&p->right?p->right->height:0;*/
    return hl-hr;
}
struct Node *LLRotation(struct Node *p)
{
    struct Node *pl=p->left;
    struct Node *plr=pl->right;

    pl->left=p;//Make p left child of pl
    p->left=plr;//make left child of p pont to plr

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
    root=pl;

    return pl;

    
}
struct Node *insertBST(struct Node *root,int x)
{   
    if(root==NULL)
    {
          root=(struct Node*)malloc(sizeof(struct Node));
          root->data=x;
          root->left=NULL;//It is important to make left and right child of leaf node as NULL
          
          root->right=NULL;
          
       
          return root;
    }
       
    else if(root->data>x)
    {root->left=insertBST(root->left,x);}
    else if(root->data<x)
    {
       root->right=insertBST(root->right,x);
    }
    root->height=NodeHeight(root);
     // llRotation 
    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==1)
    return LLRotation(root);
//    //LRRotation
//     if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
//    return LRRotation(p);
    return root;
}
void preorder(struct Node *root)
{
	if(root!=NULL)
	{  	printf("data: %d ",root->data);
		preorder(root->left);
	
		preorder(root->right);
		
	}
}
int main()
{ 
  root=insertBST(root,15);
  insertBST(root,10);
  insertBST(root,5);
  insertBST(root,2);
  preorder(root);
  return 0;
}
