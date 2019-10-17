#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string words[n];
	for(int i=0;i<n;i++)
	{
		cin >> words[i];
	}
	string ans="";
	int flag=0;
	int n1 = words[0].length();
	for(int i=0;i<n1;i++)
	{
		char ch = words[0][i];
		for(int j=0;j<n;j++)
		{
			if(ch != words[j][i] || words[j][i]=='\0')
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			break;
		}
		else
		{
			ans+=ch;
		}
	}
	cout << ans << endl;
}
