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

map <int , int> mp;
void func(Node *root ,int hd)
{
    if(!root)
    return;
    mp[hd]=root->data;
    func(root->left,hd-1);
    func(root->right,hd+1);
}

void bottomView(Node *root)
{
   // Your Code Here
   mp.clear();
   func(root,0);
   for(auto it = mp.begin();it!=mp.end();it++)
   {
       cout << it->second << " ";
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
	bottomView(root);
}
