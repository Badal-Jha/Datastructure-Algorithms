#include<stdio.h>
#include<stdlib.h>
#include"queuefortree.h"
struct Node{
         int key;
         struct Node* right;
         struct Node* left;
}*right=NULL,*left=NULL;
void Treecreat(struct Node *root)
{
  struct Node *p,*temp;
  int x;
  struct Queue q;
  creatQueue(&q,100);
  printf("Enter root data: ");
  scanf("%d",&x);
  root->key=x;
  enqueue(&q,x);
  while(q->rear!=q->front)
  {   int x1; 
      p=dequeue(&q);
      printf("enter left child of %d ",p->key);
      scanf("%d",&x1);
      if(x1!=-1)
      {
        temp=malloc(sizeof(struct Node));
        temp->key=x1;
        temp->left=temp->right=NULL;
        p->left=temp;
        enqueue(&q,temp);


      }
      int x2;
      printf("enter right chiled of %d",p->key);
      scanf("%d",&x2);
      if(x2!=-1)
      {
         temp=malloc(sizeof(struct Node));
         temp->key=x2;
         tenp->left=temp->right=NULL;
         p->right=temp;
         enqueue(&q,t);


      }

  }



}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preoreder(root->left);
        preorder(root->right);
    }
}
int main()
{
  struct Node *root=NULL;
  Treecreat(root);
  preorder(root);
  return 0;


}