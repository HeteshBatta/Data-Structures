#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

class DoubleStack
{
	int stack[100];
	int top1;
	int top2;
	public:
	DoubleStack()
	{
		top1=-1;
		top2=100;
	}
	void push(int data)
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
	void pushtail(int data)
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
	int peak()
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
	int peaktail()
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


int main()
{

	// DoubleSided Stack
	
	DoubleStack d;
	d.push(1);
	d.pushtail(2);
	cout << d.peak() << endl;
	cout << d.peaktail() << endl;
	d.pop();
	d.poptail();
	cout << d.empty() << endl;
	cout << d.emptytail() << endl;
	
return 0;
}
