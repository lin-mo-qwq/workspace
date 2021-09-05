#include<bits/stdc++.h>
using namespace std;

int n, r;
int a[100], use[100];

void dfs(int x)
{
	if(x > r)
	{
		for(int i = 1; i <= r; i++) cout << setw(3) << a[i]; 
		puts("");
		return ;
	}
	for(int i = a[x - 1] + 1; i <= n; i++)
		if(!use[i])
			a[x] = i, use[i] = 1, dfs(x + 1), use[i] = 0;
}

int main(void)
{
	cin >> n >> r;
	dfs(1);
	return 0;
}