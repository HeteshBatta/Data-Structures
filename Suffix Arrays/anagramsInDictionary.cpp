#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string dict[n];
	string temp;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		sort(temp.begin(),temp.end());
		dict[i] = temp;
	}
	map <string,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[dict[i]]++;
	}
	map <string,int> :: iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout << "Anagrams of " << it->first << " are " << it->second << endl; 
	}
}
