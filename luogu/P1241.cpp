#include<bits/stdc++.h>
using namespace std;
string k;
bool vis[10005];
int main()
{
	cin>>k;
	for(int i = 0; i < k.length(); i++)
	{
		if(k[i] == ')' || k[i] == ']')
		{ 
			for(int j = i - 1; j >= 0; j--)
			{
				if((k[j] == '(' && k[i] == ')') || (k[j] == '[' && k[i] == ']'))
					if(!vis[j]) 
					{
						vis[i] = vis[j] = true;
						break;
					}
				if((k[j] == '[' && k[i] == ')') || (k[j] == '(' && k[i] == ']'))
					if(!vis[j]) break;
			}
		}
	}
	for(int i = 0; i < k.length(); i++)
	{	
		if(!vis[i])
		{
			if(k[i] == '(' or k[i] == ')') cout<<"()";
			else cout<<"[]";
		} 
		else cout<<k[i];
	}
	return 0;
}
