#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

int findMiddle(struct Node* head) 
{
  if(head==NULL)
  {
    return -1;
  }
    int number,count=0;
	struct Node *slow , *fast;
    slow=head;
    fast=head;
    while(fast!=NULL)
    {
      count++;
      number = slow->data;
      slow=slow->next;
      fast=fast->next;
      if(fast!=NULL)
      {
      fast=fast->next;
      count++;
      }
    }
  if(count%2==0)
  {
    number = slow->data;
    return number;
  }
  else
  {
  return number; 
  }
}

int main()
{
	int choice = 1;
	struct Node *head , *first , *temp = 0;
	first=0;
	while(choice)
	{
		head = (struct Node *)malloc(sizeof(struct Node));
		scanf("%d" , &head->data);
		if(first!=0)
		{
			temp->next=head;
			temp=head;
		}
		else
		{
			first=head;
			temp=head;
		}
		printf("Choice\n");
		scanf("%d" , &choice);
	}
	temp->next=0;
	temp=first;
	cout << findMiddle(temp);
}
