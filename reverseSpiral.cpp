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

void reverseSpiral(struct Node *root)
{
	if(!root)
        return;
    queue <struct Node*> q;
    stack <struct Node*> s;

    q.push(root);

    while (!q.empty())
    {
        struct Node* temp=q.front();
        q.pop();
        s.push(temp);

        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }

    while (!s.empty())
    {
        struct Node* temp=s.top();
        s.pop();
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
	reverseSpiral(root);
}
