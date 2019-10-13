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

int height(Node* node)
{
   // Your code here
   if(node==NULL)
   {
       return 0;
   }
   int count=0;
   int level=0;
   queue <Node *> q;
   q.push(node);
   while(!q.empty())
   {
       if(level==0)
       {
           count++;
           level = q.size();
           Node *t = q.front();
        //   cout << t->data << "*" << endl;
       }
       Node *temp = q.front();
       q.pop();
    //   cout << temp->data << " " << level << "!" << endl;
       if(temp->right!=NULL)
       {
           q.push(temp->right);
       }
       if(temp->left!=NULL)
       {
           q.push(temp->left);
       }
       level--;
   }
   return count;
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
	cout << height(root) << endl;
}
