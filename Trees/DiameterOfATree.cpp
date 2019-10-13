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

int height(Node *root)
{
    if(!root)
    return 0;
    
    return 1 + max(height(root->left) , height(root->right));
}

int diameter(Node* root)
{
   // Your code here
   if(!root)
   return 0;
   
   int lheight = height(root->left);
   int rheight = height(root->right);
   
   int ldiameter = diameter(root->left);
   int rdiameter = diameter(root->right);
   
   return max((1+lheight+rheight),max(ldiameter,rdiameter));
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
	cout << diameter(root) << endl;
}
