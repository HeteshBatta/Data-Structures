#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void print(Node *root , int sum , long long *tsum)
{
    if(!root->left && !root->right)
    {
        sum*=10;
        sum+=root->data;
        tsum+=sum;
        return;
    }
    if(root->left && root->right)
    {
        sum*=10;
        sum+=root->data;
        print(root->left,sum,tsum);
        print(root->right,sum,tsum);
    }
    else if(root->left)
    {
        sum*=10;
        sum+=root->data;
        print(root->left,sum,tsum);
    }
    else if(root->right)
    {
        sum*=10;
        sum+=root->data;
        print(root->right,sum,tsum);
    }
}
long long treePathsSum(Node *root)
{
    //Your code here
    long long ans=0;
    if(!root)
     return ans;
    print(root,0,&ans);
    return ans;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << treePathsSum(root) << endl;
  }
  return 0;
}
