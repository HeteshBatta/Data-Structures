#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

int main()
{
	int choice = 1;
	struct node *head , *first , *temp = 0;
	first=0;
	while(choice)
	{
		head = (struct node *)malloc(sizeof(struct node));
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
	while(temp!=0)
	{
		printf("%d\n" , temp->data);
		temp=temp->next;
	}
}
