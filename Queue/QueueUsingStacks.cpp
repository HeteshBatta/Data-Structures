#include<bits/stdc++.h>
using namespace std;
class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
}

void StackQueue :: push(int x)
 {
        s1.push(x);
 }
 
int StackQueue :: pop()
{
        if(s1.empty())
        {
            return -1;
        }
        while(!s1.empty())
        {
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty())
        {
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
        return ans;
}

