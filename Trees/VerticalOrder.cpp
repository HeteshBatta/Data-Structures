#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
queue <pair<Node*,int> > q;
map <int,vector<int>> mp;
void check(Node *root, int hd)
{
    if(!root)
    return;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node *,int> temp = q.front();
        q.pop();
        mp[temp.second].push_back(temp.first->data);
        if(temp.first->left)
        {
        q.push(make_pair(temp.first->left,temp.second-1));
        }
        if(temp.first->right)
        {
        q.push(make_pair(temp.first->right,temp.second+1));
        }
    }
}

void verticalOrder(Node *root)
{
    //Your code here
    //queue <pair<Node*,vector<int>>> empty;
   // swap(q,empty);
    mp.clear();
    if(!root)
    return;
    check(root,0);
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        //sort(it->second.begin(),it->second.end());
        for(int i=0;i<it->second.size();i++)
        {
            cout << it->second[i] << " ";
        }
    }
}
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}
