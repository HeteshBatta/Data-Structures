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

void check1(struct Node *root, int hd,map<int,int> &mp)
{
    if(!root)
    return;
    
    if(mp.find(hd)==mp.end() && hd>=0)
    {
        //cout << hd << " " << root->data << endl; 
        mp[hd]=root->data;
    }
    check1(root->right,hd+1,mp);
    check1(root->left,hd-1,mp);
}


void check(struct Node *root, int hd,map<int,int> &mp)
{
    if(!root)
    return;
    
    if(mp.find(hd)==mp.end() && hd<0)
    {
        //cout << hd << " " << root->data << endl; 
        mp[hd]=root->data;
    }
    check(root->left,hd-1,mp);
    check(root->right,hd+1,mp);
}

void topView(struct Node *root)
{
    //Your code here
    map <int,int> mp;
    mp.clear();
    check(root->left,-1,mp);
    check1(root,0,mp);
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
	topView(root);
}
