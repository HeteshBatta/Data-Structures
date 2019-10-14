#include <bits/stdc++.h>
using namespace std;

template <typename t>
class DoublyLinkedList{
	struct node{
		t data;
		struct node *next;
		struct node *prev;
	};
	int s=0;
	struct node *head=NULL;
	struct node *tail=NULL;
	public:
	void insertBeg(t data)
	{
		struct node *ptr = (struct node *)malloc(sizeof(struct node));
		ptr->prev=NULL;
		ptr->data=data;
		ptr->next=head;
		if(head!=NULL)
		{
			head->prev=ptr;
		}
		head = ptr;
		if(s==0)
		{
			tail = ptr;
		}
		s++;
	}
	void insertEnd(t data)
	{
		struct node *ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = data;
		ptr->next = NULL;
	    ptr->prev = tail;
	    if(tail!=NULL)
	    {
	    	tail->next = ptr;
		}
	    if(s==0)
	    {
	    	head = ptr;
		}
		tail = ptr;
		s++;
	}
	int size()
	{
		return s;
	}
    void toString()
	{
	 struct node *temp = head;
	 while(temp!=NULL)
	 {
	 	cout << temp->data << " ";
		temp=temp->next;	
	 }
	 cout << endl;	
	}
	bool isEmpty()
	{
		if(s==0)
		return false;
		else
		return true;	
	}
    t elementAtHead()
    {
    	return head->data;
	}
	t elementAtTail()
	{
		return tail->data;
	}
	void deleteFirst()
	{
		head=head->next;
		head->prev=NULL;
		size--;	
	}
	void deleteLast()
	{
	tail=tail->prev;
	tail->next=NULL;
	size--;	
	}
	void RevtoString()
	{
	struct node *temp = tail;
	while(temp!=NULL)
	{
	cout << temp->data <<" ";
	temp=temp->prev;	
	}
	cout << endl;	
    }
    void insertAt(int index , int data)
    {
    	struct node *temp = head , *pre;
    	while(index--)
    	{
    		pre = temp;
    		temp=temp->next;
		}
		struct node *ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = data;
		ptr->prev = pre;
		ptr->next = temp;
		pre->next = ptr;
		temp->prev = ptr;
	}
};

int main()
{
	DoublyLinkedList <int> d;
	d.insertBeg(1);
	d.insertEnd(2);
	d.toString();
}
