#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int from, to, key;
	friend bool operator < (edge a,edge b)
	{
		return a.key<b.key;
	}
};

vector<edge> E;
int dad[10000001], n, m, ans, cnt, k;

int anc(int x)
{
	if(x != dad[x]) return dad[x] = anc(dad[x]);
	return x;
}

void uni(int x,int y)
{
	x = anc(x), y = anc(y);
	if(x!=y) dad[x]=y;
}

bool ask(int x,int y)
{
	return anc(x) == anc(y);
}

void kruskal()
{
	for(int i = 1; i <= n; i++) dad[i] = i;
	sort(E.begin(),E.end());
	for(int i = 0; i < E.size(); i++)
	{
		if(ask(E[i].from, E[i].to)) continue;
		uni(E[i].from, E[i].to);
		ans+=E[i].key, cnt++;
		if(cnt == n - 1)
			break;
	}
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1, tmp; j <= n; j++)
		{	
			cin>>tmp;
			if(j > i) E.push_back(edge{i, j, tmp});
		}
	}
	kruskal();
	cout<<ans<<endl;
	return 0;
}