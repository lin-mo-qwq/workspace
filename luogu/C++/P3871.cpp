#include<bits/stdc++.h>
using namespace std;
#define M 100005 

int n, size;
priority_queue<int> bigger;
priority_queue<int, vector<int>, greater<int>> litter;

void swap(int a, int b)
{
	bigger.pop(), bigger.push(b);
	litter.pop(), litter.push(a);
}

void push(int x)
{
	bigger.push(x);
	litter.push(x);
	if (bigger.size() > size / 2)
	{
		if (bigger.top() > litter.top())
			swap(bigger.top(), litter.top());
	}
}

int main()
{
	cin>>n; size = n;
	for(int i = 1, s; i <= n; i++) cin>>s, push(s);
	cin>>n;
	for(int i = 1, s; i <= n; i++) 
	{
		char o[3];
		scanf("%s%d", o, &s);
		if(o[0] == 'a') size++, push(s);
		else cout<<bigger.top()<<endl;
	}
	return 0;
}