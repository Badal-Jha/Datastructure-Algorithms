#include<iostream>
#include<queue>
using namespace std;
struct Node{
          int key;
          Node *left,*right;
          Node(int x)
          {
              key=x;
              left=right=NULL;
          }


};
//Node *root=NULL;
Node *creatTree(Node *root)
{    queue<Node*>q;
      printf("ENter root data :");
     int x;
    scanf("%d",&x);
  root=new Node(x);
    Node *curr,*temp;
   q.push(root);
    while(q.empty()!=true)
    {   curr=q.front();
        q.pop();
        int x1;
       printf("enter left data of %d : ",curr->key);
       scanf("%d",&x1);
    if(x1!=-1)
    {
       temp=new Node(x1);
       curr->left=temp;
       q.push(temp);

    }
    printf("enter right child of %d : ",curr->key);
     int x2;
     scanf("%d",&x2);
     if(x2!=-1)
     {
         temp=new Node(x2);
         curr->right=temp;
         q.push(temp);
     }

    }

return root;
}
// preorder traversal

void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);

    }
    
}
//Max height of binery tree
int maxHeight(Node *root)
{
    if(root==NULL)return 0;//In case you consider the height of root node as 0 then return -1 in this case
    int h1=maxHeight(root->left);
    int h2=maxHeight(root->right);
    return max(h1,h2)+1;
}

// level order traversal
void levelorder(Node *root)
{
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
         cout<<curr->key<<" ";
         if(curr->left!=NULL)q.push(curr->left);
         if(curr->right!=NULL)q.push(curr->right);

    }
}
// level order traversal second method

void levelorder2(Node *root)
{ if(root==NULL)return ;
  queue<Node *>q;
  q.push(root);
  while(q.empty()==false)
  {
      int count=q.size();
      for(int i=0;i<count;i++)
      {
          Node *curr=q.front();
          q.pop();
          cout<<curr->key<<" ";
          if(curr->left!=NULL)q.push(curr->left);
          if(curr->right!=NULL)q.push(curr->right);
      }cout<<"\n";
  }
  

}
int main()
{
    // we have to declare root globally to work and update it in creatTree function or we can declare it in main 
    // function and passed to each function and return the root after update as we did here;
     Node *root=NULL;//if we does not want to get a return root then we should define root globally
                     //then we can update and access it without any argument passing and return;
      root=creatTree(root);
      cout<<"data are: "<<endl;
      preorder(root);
      cout<<"Level order traversal: "<<endl;
      levelorder(root);
      cout<<"second method level order"<<endl;
      levelorder2(root);
        cout<<"Max height of Tree: "<<maxHeight(root)<<endl;
      return 0;

}