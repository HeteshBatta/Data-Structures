#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(!root)
   return root;
   while(root!=NULL)
   {
       if((n1 > root->data && n2 < root->data) || (n1 < root->data && n2 > root->data))
       break;
       else if(n1==root->data || n2==root->data)
       break;
       else if(n1 > root->data && n2 > root->data)
       {
       if(root->right)
       root = root->right;
       else
       break;
       }
       else
       {
       if(root->left)
       root = root->left;
       else
       break;
       }
   }
   return root;
}

int main()
{
	struct Node *root=NULL;
	map <int,Node *> m;
	int n;
	cin >> n;
	while(n--)
	{
		struct Node *parent , *child;
		char ch;
		int p,c;
	    cin >> p >> c;
	    cin >> ch;
	    if(m.find(p)==m.end())
	    {
	    	parent = new Node(p);
	    	m[p] = parent;
			if(root==NULL)
			{
				root = parent;
			}
		}
		else
		{
			parent = m[p];
		}
		child = new Node(c);
		if(ch=='L')
		parent->left = child;
		else
		parent->right = child;
		m[c] = child;
	}
	int n1,n2;
	cin >> n1 >> n2;
    Node *res = LCA(root,n1,n2);
    cout << res->data << endl;
}
