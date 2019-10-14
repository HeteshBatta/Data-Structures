#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node* reverse(struct Node* head) 
{
  struct Node *prev = NULL;
  struct Node *current = head;
  struct Node *nextt;
  while(current!=NULL)
  {
    nextt=current->next;
    current->next=prev;
    prev=current;
    current=nextt;
  }
  head=prev;
  return head;
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
	temp = reverse(temp);
	while(temp!=0)
	{
		printf("%d\n" , temp->data);
		temp=temp->next;
	}
}
