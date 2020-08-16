#include<bits/stdc++.h>
using namespace std;

string k;
stack <char> S;
deque <char> ans;

void push(char x)
{
	if(x=='['||x=='(')
		S.push(x);

	if(S.empty())
		return  ;
		
	if((S.top()=='('&&x==')')||(S.top()=='['&&x==']'))
		ans.push_back(S.top()),ans.push_back(x),S.pop();


}

int main()
{
	cin>>k;

	for(int i=0;i<k.size();i++)
		push(k[i]);	
		

	while(!S.empty())
	{
		if(S.top()=='[')
			ans.push_front(']'),ans.push_front('[');
		else
			ans.push_front(')'),ans.push_front('(');
		
		S.pop();
	}

	for(auto i:ans)
		cout<<i;

	return 0;
}
