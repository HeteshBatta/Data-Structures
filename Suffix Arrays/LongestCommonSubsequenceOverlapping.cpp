#include <bits/stdc++.h>
using namespace std;
int main()
{
	string word;
	cin >> word;
	map <string,int> mp;
	int n = word.length();
	string temp;
	for(int i=0;i<n;i++)
	{
		temp = word.substr(i,n-i);
		mp[temp]=1;
	}
	map <string,int> :: iterator it , itr;
	int n1,n2,max=-1;
	string fans;
	for(it=mp.begin();itr!=mp.end();it++)
	{
		string str1,str2;
		str1 = it->first;
		n1 = str1.length();
		itr = it;
		itr++;
		if(itr==mp.end())
		{
			break;
		}
		str2 = itr->first;
		n2 = str2.length();
		int c=0;
		string ans="";
		for(int j=0;j<n1 && j<n2;j++)
		{
			if(str1[j]==str2[j])
			{
				c++;
				ans+=str1[j];
			}
			else
			{
				break;
			}
		}
		if(c>max)
		{
			max = c;
			fans = ans;
		}
	}
	cout << fans << " " << max << endl;
	return 0; 
}
