#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void mirror(struct Node* node)
{
	if(node!=NULL)
     {
     queue <Node *> q;
     q.push(node);
     Node *t = NULL , *t1 = NULL;
     Node *n = (Node *)malloc(sizeof(Node));
     while(!q.empty())
     {
         Node *temp = q.front();
         q.pop();
         if(temp->right)
         {
             t = temp->right;
             q.push(t);
             temp->right=NULL;
         }
         if(temp->left)
         {
             t1 = temp->left;
             q.push(t1);
             temp->left=NULL;
         }
         if(t!=NULL)
         {
             temp->left = t;
             t = NULL;
         }
         if(t1!=NULL)
         {
             temp->right = t1;
             t1 = NULL;
         }
     }
     }
}
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     mirror(root);
     inOrder(root);
     cout << endl;
  }
  return 0;
}
