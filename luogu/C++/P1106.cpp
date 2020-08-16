#include<bits/stdc++.h>
using namespace std;

int n,k;
stack <int> rss;
deque <int> ans; 

void push(int x)
{
	while ( !rss.empty() )
	{
		if(k!=0 && rss.top() > x)
			rss.pop(),k--;
		else
			break;
	}

	rss.push(x);

	if( k!=0 &&rss.top()==0)
		while(!rss.empty())
		{
			if(rss.top()==0)
				rss.pop();

			else
				break;
		}
}	

int main()
{

	string res;
	cin>>res;
	cin>>k;
	for(int i=0;i<res.size();i++)
		push(res[i]-'0');

	
	while(k!=0 && !rss.empty())
		rss.pop(),k--;
	
	while (!rss.empty())
	{
		
		ans.push_front(rss.top());
		rss.pop();
	}

	
	while(!ans.empty())
	{
		cout<<ans.front();
		ans.pop_front();
	}

	puts("");

	
	return 0;
}