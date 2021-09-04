#include<bits/stdc++.h>
using namespace std;
const int M = 55;
int n, h[M], up[M], down[M];

bool dfs(int depth, int u, int su, int sd)
{
	if(su + sd > depth) return false;
	if(u > n) return true;

	bool flag = true;
	for(int i = 1, t; i <= su; i++)
		if(h[u] > up[i])
		{
			t = up[i]; up[i] = h[u];
			if(dfs(depth, u + 1, su, sd)) return true;
			flag = false; up[i] = t; break;
		}
	if(flag) 
	{
		up[su + 1] = h[u];
		if(dfs(depth, u + 1, su + 1, sd)) return true;
	}

	flag = true;
	for(int i = 1, t; i <= sd; i++)
		if(h[u] < down[i])
		{
			t = down[i], down[i] = h[u];
			if(dfs(depth, u + 1, su, sd)) return true;
			flag = false, down[i] = t;
		}
	if(flag)
	{
		down[sd + 1] =  h[u];
		if(dfs(depth, u + 1, su, sd + 1)) return true;
	}

	return false;
}

int main()
{
	while(cin>>n, n) 
	{
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		for(int i = 1; i <= n; i++) cin>>h[i];
		int depth = 0;	
		while(!dfs(depth, 1, 0, 0)) depth++;
		cout<<depth<<endl;
	}
	return 0;
}