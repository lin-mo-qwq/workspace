#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int from, to, key;
	friend bool operator < (edge a,edge b)
	{
		if(a.from < b.from) return true;
		else if(a.from == b.from && a.to < b.to) return true;
		else return false;
	}
	void ins()
	{
		cin>>from>>to;
		if(from > to) swap(from, to);
	}	
};

vector<edge> E;
int dad[10005], n, m, ans, cnt, k;

int anc(int x)
{
	if(x != dad[x]) return dad[x] = anc(dad[x]);
	return x;
}

void uni(int x,int y)
{
	x = anc(x), y = anc(y);
	if(x!=y) dad[x]=y, cnt++;
}

bool ask(int x,int y)
{
	return anc(x) == anc(y);
}

void kruskal()
{
	sort(E.begin(),E.end());
	for(int i = 0; i < m; i++)
	{
		cnt = 0;
		for(int j = 1; j <= n; j++) dad[j] = j;
		for(int j = 0; j < m; j++)
		{
			if(i != j) uni(E[j].from, E[j].to);
			if(cnt == n - 1) break;
		}
		if(cnt == n - 1) continue;
		else cout<<E[i].from<<' '<<E[i].to<<endl;
	}
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
	{
		edge s; s.ins();
		E.push_back(s);
	}
	kruskal();
	return 0;
}