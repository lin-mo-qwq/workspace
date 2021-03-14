#include<bits/stdc++.h>
using namespace std;
const int N = 25005;
int n, f[N], ret[N], vis[N], ans;
int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			 scanf("%d", &ret[i]);		
		sort(ret + 1, ret + 1 + n);
		
		f[0] = 1;
		
		for(int i = 1; i <= n; i++)
			for(int j = ret[i]; j <= ret[n]; j++)
			{
					f[j] |= f[j - ret[i]];  
					if(f[j] == 1 && f[j] == f[j - ret[i]] && j != ret[i])
						vis[j] = 1;
			}
		
		for(int i = 1; i <= n; i++)
			if(!vis[ret[i]]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}