// Circular Linked List
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

// Doubly Linked List

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

// Singly Linked List

template <typename t>
class LinkedList
{
	struct node
	{
		t data;
		struct node *next;	
	};
	struct node *head = NULL;
	struct node *tail = NULL;
	int s=0;	
	public:
		void push(t data)
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			if(head==NULL)
			{
				ptr->data = data;
				ptr->next = NULL;
				head=ptr;
				tail=ptr;
			}
			else
			{
				ptr->data = data;
				ptr->next = NULL;
				tail->next = ptr;
				tail = ptr;
			}
			s++;
		}
		t elementAtHead()
		{
			return head->data;
		}
		t elementAtTail()
		{
			return tail->data;
		}
		void insertAtFirst(t data)
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data = data;
			ptr->next = head;
			head = ptr;
			s++;
		}
		void insertInBetween(int index , t data)
		{
			if(index>s)
			{
				cout << "Size too less" << endl;
			}
			else
			{
				struct node *ptr = head;
				while(index>1)
				{
					ptr = ptr->next;
					index--;
				}
				struct node *newest = (struct node *)malloc(sizeof(struct node));
				newest->data = data;
				newest->next = ptr->next;
				ptr->next = newest;
				s++;
			}
		}
		void removeFirst()
		{
			head = head->next;
			s--;
		}
		bool isEmpty()
		{
			if(head==NULL)
			{
				return true;		
			}
			else
			{
				return false;
			}
		}
		int size()
		{
			return s;
		}
		void toString()
		{
			struct node *ptr = head;
			cout << "( ";
			while(ptr!=NULL)
			{
				cout << ptr->data << " ";
				ptr=ptr->next;
			}
			cout << ")" << endl;
		}
		void deletefrombetween(int index)
		{
			if(index>s)
			{
				cout << "Too few elements" << endl;
			}
			else
			{
			struct node *ptr = head;
			struct node *prev=head;
			while(index--)
			{
				prev=ptr;
				ptr=ptr->next;
			}
			prev->next = ptr->next;
			s--;
			}
		}
};

// Stack Using Array

template <typename t>
class stacks
{
	virtual void push(t d)=0;
	virtual void pop()=0;
	virtual t peak()=0;
	virtual bool empty()=0;	
};

template <typename t> 
class ArrayStack : public stacks<t>
{
	t stack[100];
	int top;	
	public:
		ArrayStack()
		{
			top=-1;
		}
		void push(t data)
		{
			if(top==100)
			{
				printf("Overflow\n");
			}
			else
			{
			top++;
			stack[top]=data;
		    }
		}
		t peak()
		{
			if(top==-1)
			{
				printf("No elements\n");
			}
			else
			{
			return stack[top];
		    }
		}
		void pop()
		{
			if(top==-1)
			{
				printf("Underflow\n");
			}
			else
			top--;
		}
		bool empty()
		{
			if(top==-1)
			{
				return true;
			}
			else
			{
				return false;
			}	
		}
};

// Two stacks Implemented In a Single Array

template <typename t>
class DoubleStack : public stacks<t>{
	t stack[100];
	int top1;
	int top2;
	public:
	DoubleStack()
	{
		top1=-1;
		top2=100;
	}
	void push(t data)
	{
		if(top1==top2-1)
		{
			printf("Overflow\n");
		}
		else
		{
		top1++;
		stack[top1]=data;
	    }
    }
	void pushtail(t data)
	{
		if(top1==top2-1)
		{
			printf("Overflow\n");
		}
		else
		{
		top2--;
		stack[top2]=data;
	    }
	}
	t peak()
	{
		if(top1==-1)
		{
			printf("No elements are inserted\n");
		}
		else
		{
			return stack[top1];
		}
	}
	t peaktail()
	{
		if(top2==100)
		{
			printf("No elements are inserted\n");
		}
		else
		{
			return stack[top2];
		}
	}
	void pop()
	{
		if(top1==-1)
		{
			cout << "Underflow" << endl;
		}
		else
		{
			top1--;
		}
	}
	void poptail()
	{
		if(top2==100)
		{
			cout << "Underflow" << endl; 
		}
		else
		{
			top2++;
		}
	}
	bool empty()
	{
		if(top1==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool emptytail()
	{
		if(top2==100)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


// Stack Using Linked List

template <typename t>
class LinkedStack : public stacks<t>
{
	public:
	struct node{
		t data;
		struct node* next;
	};
	struct node *head = NULL;
	void push(t data)
	{
		if(head==NULL)
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data=data;
			ptr->next=NULL;
			head = ptr;
		}
		else
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data = data;
			ptr->next = head;
			head = ptr;
		}
	}
	bool empty()
	{
		if(head==NULL)
		{
			return true;
		}
		else
		return false;
	}
	void pop()
	{
		head= head->next;
	}
	t peak()
	{
		return head->data;
	}
};
