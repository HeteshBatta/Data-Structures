#include <bits/stdc++.h>
using namespace std;
int main()
{
	char str[100000];
	gets(str);
	
	char* token = strtok(str, " "); 
    map <string,int> mp;
    while (token != NULL) 
	{ 
        mp[token]++; 
        token = strtok(NULL, " "); 
    } 
    map <string,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
    	cout << it->first << " " << it->second << endl;
	}
}
