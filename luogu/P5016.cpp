#include<bits/stdc++.h>
using namespace std;
int s[5];
int t[5][21], l, r, ans, fast; 

void solve(int x, int size)
{
	if(x > s[size])
	{
		fast = min(fast, max(l, r)); return;
	}
	l += t[size][x];
	solve(x + 1, size);
	l -= t[size][x];
	r += t[size][x];
	solve(x + 1, size);
	r -= t[size][x];
}

int main()
{
	for(int i = 1; i <= 4; i++) cin>>s[i];
	for(int i = 1; i <= 4; i++)
	{
		l = r = 0, fast = 2147483647;
		for(int j = 1; j <= s[i]; j++)
			cin>>t[i][j];
		solve(1, i), ans += fast;
	}
	cout<<ans<<endl;
	return 0;
}