#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* mergeKLists(Node* arr[], int N);

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}
Node *newNode(int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;
           int x;
           cin>>x;
           arr[j]=newNode(x);
           Node *curr = arr[j];
           n--;
           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = newNode(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Node *res = mergeKLists(arr,N);
		printList(res);
   }
	return 0;
}

struct compare 
{ 
    bool operator()(struct Node* a, struct Node* b) 
    { 
        return a->data > b->data; 
    } 
}; 
Node * mergeKLists(Node *arr[], int n)
{
       Node *head = NULL , *last = NULL; 
       priority_queue <Node * , vector <Node*> , compare> pq; 
       for(int i=0;i<n;i++)
       {
           pq.push(arr[i]);
       }
       while(!pq.empty())
       {
           Node *top = pq.top();
           pq.pop();
           if(top->next!=NULL)
           {
               pq.push(top->next);
           }
           if(head==NULL)
           {
               head = top;
               last = top;
           }
           else
           {
               last->next = top;
               last=top;
           }
       }
       return head;
}

