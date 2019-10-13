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

void postorderIterative(struct Node *root)
{
	if(!root)
        return;
    stack<struct Node* > s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        struct Node* temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        struct Node* temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
    
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
	postorderIterative(root);
}
