#include<bits/stdc++.h>
using namespace std;

int n;
int fa[21][105], d[105],deep,w[105];
vector <int> V[105];

void inp()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
}

void dfs(int x)
{
	for(int i=0;i<V[x].size();i++)
	{
		int v=V[x][i];
		deep = max(deep,d[x]);
		if(v==fa[0][x])	continue;
		w[d[x]]++;
		d[v]=d[x]+1;
		fa[0][v]=x;
		dfs(v);
	}
}

void build()
{
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++)
			fa[i][j]=fa[i-1][fa[i-1][j]];
}

int ask(int x,int y)
{
	if(d[x]>d[y])
		swap(x,y);
	
	int temp=d[y]-d[x];

	
	for(int i=20;i>=0;i--)
		if(temp>=(1 << i))
			y=fa[i][y],temp-=(1<<i);
	
	if(x==y)
		return x;

	for(int i=20;i>=0;i--)
		if(fa[i][y]!=fa[i][x])
			x=fa[i][x], y=fa[i][y];

	return fa[0][y];

}


int main()
{
	int u,v,lca;
	inp();
	cin>>u>>v;
	fa[0][1]=1;
	d[1]=1;
	dfs(1);
	build();
	sort(w+1,w+1+n);
	lca = ask(u,v);
	cout<<deep<<endl<<w[n]<<endl<<(d[u]-d[lca])*2+(d[v]-d[lca]);
	return 0;
}