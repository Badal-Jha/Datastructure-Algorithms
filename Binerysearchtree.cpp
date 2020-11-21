#include<iostream>
using namespace std;
struct Node{
     int data;
     Node *left;
     Node *right;
     Node(int x){
         data=x;
         left=right=NULL;
     }

};
Node *Bsearch(Node *root,int key)
{   Node *t=root;
    if(root==NULL)return NULL;
    if(key==t->data)
    {
     Node *temp=new Node(12);
     t->left=temp;
     return t;
    }
    else if(key<t->data)
    {
        Bsearch(t->left,key);
    }
    else
    {
        Bsearch(t->right,key);
    }
    //return NULL;


}
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *root=new Node(8);
    root->left=new Node(6);
     root->right=new Node(10);
     root->left->left=new Node(4);
     root->left->right=new Node(7);
     root->right->left=new Node(9);
     root->right->right=new Node(11);
    preorder(root);
    cout<<Bsearch(root,15)<<" ";
    preorder(root);
    return 0;
}