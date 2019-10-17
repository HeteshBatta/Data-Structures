#include<bits/stdc++.h>
using namespace std;

typedef struct TrieNode{
    struct TrieNode *child[256];
    bool isLeaf;
}Trie;

Trie* getNode()
{
    Trie *newNode = NULL;
    newNode = (Trie *)malloc(sizeof(Trie));
    
    if(newNode)
    {
        newNode->isLeaf = false;
        for(int i=0;i<256;i++)
        {
            newNode->child[i]=NULL;
        }
    }
    return newNode;
}

void insert(Trie *root , string word)
{
    int level = 0;
    int len = word.length();
    
    Trie *temp = root;
    
    for(level=0;level<len;level++)
    {
        if(!temp->child[word[level]])
        {
            temp->child[word[level]] = getNode();
        }
        temp = temp->child[word[level]];
    }
    
    temp->isLeaf = true;
}


bool search(Trie *temp ,string query)
{
    int len = query.length();
    
    Trie *root = temp;
    
    for(int i=0;i<len;i++)
    {
        if(!root->child[query[i]])
        {
            //cout << query[i] << "  here " << endl;
            return false;
        }
        root=root->child[query[i]];
    }
    return (root!=NULL && root->isLeaf);
}


int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	  int n;
	  cin >> n;
	  string words[n];
	  for(int i=0;i<n;i++)
	  {
	      cin >> words[i];
	  }
	  
	  Trie *root = NULL;
	  root = getNode();
	  
	  for(int i=0;i<n;i++)
	  {
	      insert(root,words[i]);
	  }
	  
	  string str;
	  cin >> str;
	  if(search(root,str))
	  cout << "1\n";
	  else
	  cout <<"0\n";
	}
	return 0;
}
