#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *left,*right;
};

 
struct Node *create(struct Node *root)
{
struct Node *p=root;
	int x;
	printf("Enter data(-1 for NULL):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(struct Node*)malloc(sizeof(struct Node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=create(p->left);
 
	printf("Enter right child of %d:\n",x);
	p->right=create(p->right);
	
	return p;
}

// inorder traversal: first call left child then print data than call right child
void inorder(struct Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		
		printf("%d ",root->data);
		
		inorder(root->right);
	}
}

//preorder traversal:  first print the data then call left child then call right child
void preorder(struct Node *root)
{
	if(root!=NULL)
	{    printf("%d ",root->data);   
	
	  	inorder(root->left);
		
		inorder(root->right);
	}
}

//postorder traversal: first call left child then right child then print data
void postorder(struct Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		
		inorder(root->right);
		
		printf("%d ",root->data);
	}
}
int main()
{
	struct Node *root=NULL;
	root=create(root);
	printf("\ninoreder traversal: ");
	inorder(root);
	printf("\npreorder traversal: ");
	preorder(root);
	printf("\npostorder traversal: ");
	postorder(root);
	
	return 0;
}
