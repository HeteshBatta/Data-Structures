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

void rightView(Node *root)
{
   queue <Node *> q;
   q.push(root);
   int s=1 , flag=1;
   while(!q.empty())
   {
        if(s==0)
        {
            s = q.size();
            flag=1;
        }
        Node *temp = q.front();
        q.pop();
        if(flag==1)
        {
            cout << temp->data << " " ;
            flag=0;
        }
        if(temp->right)
        q.push(temp->right);
        if(temp->left)
        q.push(temp->left);
        s--;
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
	rightView(root);
}
