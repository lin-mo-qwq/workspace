#include<bits/stdc++.h>
using namespace std;
vector<int> plan[1005];
int n, m, f[1005];
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		int v, w;
		cin>>v>>w;
		for(int j = m; j >= v; j--)
		{
			if(f[j] < f[j - v] + w) 
				f[j] = f[j - v] + w, plan[j] = plan[j - v], plan[j].push_back(i);
			if(f[j] == f[j - v] + w && plan[j] >= plan[j - v])
				plan[j] = plan[j - v], plan[j].push_back(i);
		}
	}
	for(auto i : plan[m]) cout<<i<<' ';
	return 0;
}