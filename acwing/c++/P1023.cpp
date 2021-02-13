#include<bits/stdc++.h>
using namespace std;
int m, book[] = {0, 10, 20, 50, 100}, f[1005];
int main()
{
	cin>>m;
	f[0] = 1;
	for(int i = 1; i <= 4; i++)
		for(int j = 0; j <= m; j++)	
			if(j >= book[i]) f[j] += f[j - book[i]];
	cout<<f[m];
	return 0;
}