#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head)
{
	struct Node *newhead = head;
    int x=0,count=0,count1=0;
    int stack[51];
    while(head!=NULL)
    {
        stack[x]=head->data;
        x++;
        head=head->next;
        count++;
    }
    while(newhead!=NULL)
    {
        if(newhead->data == stack[x-1])
        {
            count1++;
        }
        x--;
        newhead=newhead->next;
    }
    if(count==count1)
    return true;
    else
    return false;
}

int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}
