#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
} *root = NULL;
void insert(int x)
{
    if (root == NULL)
    {
        Node *temp = new Node(x);
        root = temp;
        return;
    }
    Node *curr = root;
    Node *parent = NULL;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->data == x)
            return;
        else if (x > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    Node *temp = new Node(x);
    if (x > parent->data)
        parent->right = temp;
    else
        parent->left = temp;
}


//To find inorder successor
Node *getSuccesor(Node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
    curr=curr->left;
    return curr;
}

//deletion in binery search tree
Node *deletNode(Node *root, int key)
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
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *succ=getSuccesor(root);
            root->data=succ->data;
            root->right=deletNode(root->right,succ->data);
        }
    }
    return root;
}

//Inoreder traversal gives data of binery search tree in sorted order
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";

        Inorder(root->right);
    }
}
void levelOrder(Node *root)
{
    Node *curr, *p;
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (q.empty() != true)
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }
}
int MinElement(Node *root)
{
    Node *curr = root;
    if (root == NULL)
    {
        printf("tree is empty\n");
        return -1;
    }

    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}
int main()
{

    insert(10);
    insert(5);
    insert(15);
    insert(12);
    insert(18);
   
    insert(20);
   
    levelOrder(root);

    cout << "minimum value: " << MinElement(root) << endl;
    deletNode(root,10);
    levelOrder(root);
}