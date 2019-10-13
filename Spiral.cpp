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

void spiral(struct Node *root)
{
	if(!root)
        return ;

    int oddLevel=true;
    stack<struct Node*> s;
    queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            struct Node* temp = q.front();
            q.pop();

            if(oddLevel)
                s.push(temp);
            else
            {
                cout<<temp->data<<" ";
            }

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

        if(oddLevel)
        {
            while(!s.empty())
            {
                struct Node* temp=s.top();
                s.pop();
                cout<<temp->data<<" ";
            }
        }

        oddLevel = (oddLevel == 1)?0 : 1;
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
	spiral(root);
}
