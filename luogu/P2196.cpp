#include<bits/stdc++.h>
using namespace std;

#define M 35

int n, f[M][M], path[M], key[M], ans, ans_ret[M], cnt;

void dfs(int x, int ret)
{
	for(int i = x + 1; i <= n; i++)	
		if(f[x][i])
			path[x] = i, dfs(i, ret + key[i]);
	if(ret > ans) 
	{
		ans = ret; cnt = 0;
		for(int i = path[0]; i; i = path[i])  ans_ret[++cnt] = i;
	}
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>key[i];
	for(int i = 1; i <= n; i++)	
		for(int j = i + 1; j <= n; j++) cin>>f[i][j];
	for(int i = 1; i <= n; i++) path[0] = i, dfs(i, key[i]);
	for(int i = 1; i <= cnt; i++) cout<<ans_ret[i]<<' ';
	cout<<endl<<ans<<endl;
	return 0;
}