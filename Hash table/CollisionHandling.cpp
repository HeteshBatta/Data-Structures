#include <bits/stdc++.h>
using namespace std;

int hash_function(int k)
{
	return k%10;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	map <int , vector<int> > mp;
	for(int i=0;i<n;i++)
	{
		int temp = hash_function(arr[i]);
		mp[temp].push_back(arr[i]);
	}
	map <int,vector<int> > :: iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout << it->first << " ";
		for(int j=0;j<it->second.size();j++)
		{
			cout << it->second[j] << " ";
		}
		cout << endl;
	}
}
