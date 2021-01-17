#include<bits/stdc++.h>
using namespace std;
bool del[1005];
int n, ret[1005], qua, f[1005], ans, f1[1005]; 
int main()
{
	while(cin>>ret[++n]) f[n] = 1;
	for(int i = n; i >= 1; i--)
		for(int j = n; j > i; j--)
			if(ret[i] >= ret[j]) f[i] = max(f[i], f[j] + 1);
	for(int i = 1; i <= n; i++)	ans = max(ans, f[i]);
	cout<<ans<<endl; ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(ret[i] > ret[j]) f1[i] = max(f1[i], f1[j] + 1);
	for(int i = 1; i <= n; i++)	ans = max(ans, f1[i]);
	cout<<ans + 1<<endl;
	return 0;
}