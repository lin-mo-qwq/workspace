#include<bits/stdc++.h>
using namespace std;	
#define v first
#define w second
typedef pair<int, int> PII;
const int N = 70, M = 32010;

int n, m, f[M];
PII master[N];
vector<PII> servent[N];

int main()
{
	cin>>m>>n;
	
	for(int i = 1; i <= n; i++)
	{
		int v, p, q;
		cin>>v>>p>>q;
		if(!q) master[i] = {v, v * p};
		else servent[q].push_back({v, v * p});
	}

	for(int i = 1; i <= n; i++)
	{
		if(!master[i].v) continue;
		for(int j = m; j >= 0; j--)
		{
			auto &sv = servent[i]; 
			for(int k = 0; k < 1 << sv.size(); k++)
			{
				int v = master[i].v, w = master[i].w;
				for(int u = 0; u < sv.size(); u++)
					if(k >> u & 1) 
						v += sv[u].v, w += sv[u].w;
				if(j >= v)
					f[j] = max(f[j], f[j - v] + w);
			}
		}
	}
	
	cout<<f[m];
	return 0;
}