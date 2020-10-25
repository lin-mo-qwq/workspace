#include<bits/stdc++.h>
using namespace std;
#define clr(x) memset(x, 1, sizeof(x))

int n, ans = 0x7fffffff;
int a[15],b[15];

void dfs(int x, int s, int w)
{
	if(x > n)
	{
		if(s == 1 && w == 0) return;
		ans = min(ans, abs(s - w));
		return;
	}

	dfs(x + 1, s * a[x], w + b[x]);
	dfs(x + 1, s, w);
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i]>>b[i];
	dfs(1, 1, 0);
	cout<<ans<<endl;
	return 0;
}