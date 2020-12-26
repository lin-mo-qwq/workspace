#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x, y;
	double len;
	friend bool operator < (node a, node b)
	{
		return a.len < b.len;
	}
} ;

node poi[1005];
vector<node> E;
int dad[1005], n, k, tot;

int anc(int x)
{
	if(x != dad[x]) return dad[x] = anc(dad[x]);
	return x;
}

void uni(int x, int y)
{
	x = anc(x), y = anc(y);
	if(x != y)
		dad[y] = x;
}

bool ask(int x, int y)
{
	return anc(x) == anc(y);
}

double size(int i, int j)
{
	return sqrt(pow((poi[i].x - poi[j].x), 2) + pow((poi[i].y - poi[j].y), 2));
}

void kruskal()
{
	for(int i = 1; i <= n; i++) dad[i] = i;
	sort(E.begin(), E.end());
	for(auto i : E)
	{
		if(ask(i.x, i.y)) continue;
		uni(i.x, i.y), tot++;
		if(tot == n - k + 1) printf("%.2lf\n", i.len), exit(0);		
	}
}

int main()
{
	cin>>n>>k;
	for(int i = 1; i <= n; i++) cin>>poi[i].x>>poi[i].y;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(j != i) E.push_back((node){i, j, size(i, j)});
	kruskal();
	return 0;
}