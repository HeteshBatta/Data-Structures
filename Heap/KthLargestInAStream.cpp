#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n , k;
	    cin >> k;
	    cin >> n;
	    int arr[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        cin >> arr[i]; 
	    }
	    priority_queue <int, vector<int>, greater<int> > pq; 
	    for(int i=1;i<k;i++)
	    {
	        pq.push(arr[i]);
	        cout << "-1 ";
	    }
	    pq.push(arr[k]);
	    cout << pq.top() << " ";
	    for(int i=k+1;i<=n;i++)
	    {
	        if(arr[i] > pq.top())
	        {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	        cout << pq.top() << " ";
	    }
	    cout << endl;
	}
	return 0;
}
