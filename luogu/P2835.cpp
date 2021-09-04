#include<bits/stdc++.h>
using namespace std;

int G[205][205], n, ans, f[205];

int main()
{
	cin>>n;
	for(int i = 1, tmp; i <= n; i++)
		while(cin>>tmp,tmp) G[i][tmp] = 1;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(G[i][k] && G[k][j]) G[i][j] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(G[i][j]) f[j] = f[i];
	for(int i = 1; i <= n; i++) if(f[i] == i)ans++;
	cout<<ans<<endl;
	return 0;
}