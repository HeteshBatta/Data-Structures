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
		mp[temp]=i;
	}
	map <string,int> :: iterator it,itr;
	int max = -1;
	string fans;
	for(it=mp.begin();it!=mp.end();it++)
	{
		itr=it;
		itr++;
		if(itr==mp.end())
		{
			break;
		}
		int fi = it->second , si = itr->second , sin , ein;
		string fs = it->first , ss = itr->first;
		if(fi < si)
		{
			sin = fi;
			ein = si;
		}
		else
		{
			sin = si;
			ein = fi;
		}
		int c=0;
		string ans="";
		///cout << fs << " " << fi << " " << ss << " " << si << endl;
		int check = ein;
		for(;sin<check && ein<n;sin++,ein++)
		{
			if(word[sin]==word[ein])
			{
				c++;
				ans += word[sin];
				//cout << word[sin] << " " << sin << " " << 
			}
			else
			{
				break;
			}
		}
		if(c > max)
		{
			max = c;
			fans = ans;
		}
	}
	cout << max << " " << fans;
}
