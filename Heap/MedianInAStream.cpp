#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	
	priority_queue<int> maxheap;
	priority_queue<int,vector<int>,greater<int> > minheap;
	
	int med=a[0];
	maxheap.push(med);
	cout<<med<<endl;
	
	for(int i=1;i<n;i++){
	    int x=a[i];
	    if(maxheap.size() > minheap.size())
	    {
	        if(x<med){
	            minheap.push(maxheap.top());
	            maxheap.pop();
	            maxheap.push(x);
	        }
	        else{
	            minheap.push(x);
	            
	        }
	        med=(maxheap.top()+minheap.top())/2;
	    }
	    else if(maxheap.size()==minheap.size()){
	        if(x<med){
	            maxheap.push(x);
	            med=maxheap.top();
	        }
	        else
	        {
	            minheap.push(x);
	            med=minheap.top();
	        }
	    }
	    else{
	        if(x>med){
	            maxheap.push(minheap.top());
	            minheap.pop();
	            minheap.push(x);
	        }
	        else{
	            maxheap.push(x);
	            
	        }
	        med=(maxheap.top()+minheap.top())/2;
	    }
	    
	    cout<<med<<endl;
	    
	}
	
	
	return 0;
}
