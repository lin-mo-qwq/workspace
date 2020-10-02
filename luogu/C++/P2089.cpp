#include<bits/stdc++.h>
using namespace std;

struct chi 
{
	int a[15];
};

int cnt, del;
vector <chi> ans;

void dfs(int x, int add, chi a, int n)
{
	if(x > 10)
	{
		if(add == n)
			cnt++, ans.push_back(a);
		else return;
	}
	for(int i = 1; i <= 3; i++)
		a.a[x] = i, dfs(x + 1, add + a.a[x], a, n), a.a[x] = 0;
}

int main()
{
	int n;
	chi a;
	
	cin >> n;
	
	dfs(1, 0, a, n);
	
	if(cnt == 0)
		cout << 0, exit(0);

	cout << cnt << endl;
	
	for(int i = 0; i < cnt; i++)
	{
		for(int j = 1; j <= 10; j++)
			cout << ans[i].a[j] <<' ';
		cout << endl;
	}
	
	return 0;
}