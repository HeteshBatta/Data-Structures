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

vector <int> v;

void inorder1(Node *root , vector <int> &v)
{
    if(!root)
    return;
    inorder1(root->left,v);
    v.push_back(root->data);
    inorder1(root->right,v);
}

bool isBST(Node* root) 
{
    // Your code here
    if(!root)
    return true;
    v.clear();
    inorder1(root,v);
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i] > v[i+1])
        return false;
    }
    return true;
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
	cout << isBST(root);
}
