#include <bits/stdc++.h>
using namespace std;

int n, k;
string res;
stack<int> rss;
deque<int> ans;

void push(int x , int i)
{
	while (!rss.empty())
	{
		if(k != 0 && rss.top() > x)
			rss.pop(), k--;
		else break;
	}
	if(x == 0 && rss.empty() && i + 1 < res.length()) return;
	rss.push(x);
}

int main()
{
	cin >> res; cin >> k;
	for (int i = 0; i < res.size(); i++)
		push(res[i] - '0', i);
	
	while (k != 0 && !rss.empty())
		rss.pop(), k--;
	
	while (!rss.empty())
	{
		ans.push_front(rss.top());
		rss.pop();
	}

	while (!ans.empty())
	{
		cout<<ans.front();
		ans.pop_front();
	}

	puts("");
	return 0;
}