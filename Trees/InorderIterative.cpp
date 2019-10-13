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

void inorderIterative(struct Node *root)
{
	    if(!root)
        return;
    stack<struct Node*> st;
    struct Node* temp = root;
    while (temp!=NULL || !st.empty())
    {
        while (temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
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
	inorderIterative(root);
}
