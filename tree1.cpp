// tree creation and level order traversal


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
Node *root=NULL;
void creatTree()
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


}
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);

    }
}
void levelorder(Node *root)
{
    if(root==NULL)return;
    Node *curr=root;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        curr=q.front();
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
void Leveloreder2(Node *root)
{
    if(root==NULL)return;
    Node *curr=root;
    queue<Node*>q;
    q.push(root);
    while(q.empty()!=true)
    {
        int cnt=q.size();
        for(int i=0;i<cnt;i++)
        {   curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
       if(curr->left!=NULL)q.push(curr->left);
        if(curr->right!=NULL)q.push(curr->right);
        }

      cout<<"\n";
    }
}
//Print data at a given level k;

void printAtK(Node *root,int k)
{
  if(root==NULL)return;
  if(k==0)
  {
      cout<<root->key<<" ";
  }
  else{
      printAtK(root->left,k-1);
      printAtK(root->right,k-1);
  }
}
void max_width(Node *root)
{
    Node *curr=NULL;
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    int res=0;
    while(q.empty()!=true)
    {
        int cnt=q.size();
        res=max(res,cnt);
        for(int i=0;i<cnt;i++)
        {  
            curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);

        }
        cout<<"\n";
      
    }
    cout<<"maximum width is: "<<res<<endl;
}
int main()
{
    
      creatTree();
      cout<<"data are: "<<endl;
      preorder(root);
      printf("\n Data in level order\n");
      levelorder(root);
      printf("\n Data in level order method 2\n");
      Leveloreder2(root);
      printf("data at distance k\n");
      printAtK(root,2);
      max_width(root);
      return 0;

}
