#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

int findNLast(struct Node* head, int n)
{
   if(head==NULL)
  {
    return -1;
  }
int number , count=0 , no1;
struct Node *ptr = head , *ptr1=head ;
while(ptr!=NULL)
{ 
  if(count>=n || ptr->next==NULL)
  {
    no1 = ptr->data;
    ptr1=ptr1->next;
  }
  ptr=ptr->next;
  count++;
}
  if(count<n)
  {
    return no1;
  }
  else
  {
  number = ptr1->data;
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
	int k;
	cin >> k;
	cout << findNLast(temp,k);
}
