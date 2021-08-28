#include<bits/stdc++.h>
using namespace std;

struct tree2
{
	int lson, rson;
} a[100005];
int n, ans;

void dfs(int x, int deepth)
{
	if(!x) return ;
	ans = max(ans, deepth);
	dfs(a[x].lson, deepth + 1);
	dfs(a[x].rson, deepth + 1);
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i].lson>>a[i].rson;
	dfs(1, 1);
	cout<<ans<<endl;
	return 0;
}