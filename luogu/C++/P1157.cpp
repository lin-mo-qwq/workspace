#include<bits/stdc++.h>
using namespace std;

int n;
int a[100], use[100];

void dfs(int x)
{
	if(x > n)
	{
		for(int i = 1; i <= n; i++) cout << setw(3) << a[i]; 
		puts("");
		return ;
	}
	for(int i = 1; i <= n; i++)
		if(!use[i])
			a[x] = i, use[i] = 1, dfs(x + 1);
}

int main(void)
{
	cin >> n;
	dfs(1);
	return 0;
}