#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
       
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

int _stack :: getMin()
{

   if(s.empty())
   {
       return -1;
   }
   else
   {
       return minEle;
   }
}

int _stack ::pop()
{
   if(s.empty())
   return -1;
   else
   {
       s.pop();
       int temp = s.top();
       s.pop();
       if(!s.empty())
       {
           minEle = s.top();
       }
       return temp;
   }
}
void _stack::push(int x)
{
   if(s.empty())
   {
       minEle = INT_MAX;
   }
   if(x < minEle)
   {
       minEle = x;
   }
   s.push(x);
   s.push(minEle);
}

