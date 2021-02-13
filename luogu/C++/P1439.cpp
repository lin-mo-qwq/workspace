#include<bits/stdc++.h>
using namespace std;

const int M = 1e5 + 5;

int n, a[M], f[M], ans, dp[M];
map <int, int> inside;

int lowbit(int x)
{
	return x & -x;
}

void add(int r, int c)
{
	for(int i = r; i <= M; i += lowbit(i)) 
		f[i] = max(f[i], c);
}

int query(int x)
{
	int res = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) res = max(res, f[i]);
	return res;
}

int read()
{
	int tmp;
	cin>>tmp;
	return tmp;
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i], inside[a[i]] = i;
	for(int i = 1, p; i <= n; i++)
		p = inside[read()], dp[i] = query(p) + 1, add(p, dp[i]); 
	cout<<query(n)<<endl;
	return 0;
}