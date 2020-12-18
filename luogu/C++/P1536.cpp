#include<bits/stdc++.h>
using namespace std;

int dad[1005], n, m, cnt;

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


int main()
{
	while(cin>>n>>m)
	{
		cnt = 0;
		for(int i = 1; i <= n; i++) dad[i] = i;
		for(int i = 1, x, y; i <= m; i++) cin>>x>>y, uni(x, y);
		for(int i = 1; i <= n; i++) 
			if(dad[i] == i) cnt++;
		cout<<cnt - 1<<endl;
	}
	return 0;
}