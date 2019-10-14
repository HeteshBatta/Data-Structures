#include <bits/stdc++.h>
using namespace std;
template <typename t>
class CircularLinkedList{
	struct node{
		t data;
		struct node* next;
	};
    struct node *tail = NULL;
    int s=0;
    public:
    	int size()
    	{
    		return s;
		}
		void insertAtHead(t data)
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data = data;
			if(s==0)
			{
				tail = ptr;
				ptr->next = tail;
			}
			else
			{
				ptr->next = tail->next;
				tail->next = ptr;
			}
			s++;
		}
		void insertAtTail(t data)
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data = data;
			if(s==0)
			{
				tail = ptr;
				ptr->next = tail;
			}
			else
			{
				ptr->next = tail->next;
				tail->next = ptr;
				tail = ptr;
			}
			s++;
		}
		t removeFirst()
		{
			int number = tail->next->data;
			tail->next=tail->next->next;
			s--;
			return number;
		}
		bool isEmpty()
		{
		if(s==0)
		return false;
		else
		return false;
		}
		void toString()
		{
			struct node *temp = tail->next;
			while(temp!=tail)
			{
				cout << temp->data <<" ";
				temp=temp->next;
			}
			cout << temp->data << endl;
		}
};

int main()
{
	CircularLinkedList <int> c;
	c.insertAtHead(1);
	c.insertAtTail(2);
	c.toString();
}

