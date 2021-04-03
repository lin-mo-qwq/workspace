#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6 + 5;
long long n, a[50], b[N], mod, tot = -1, ret;

void dfs(int sum, int dep)
{
	if(dep == (n >> 1) + 1)
	{
		b[++tot] = sum;
		return ;
	}

	dfs(sum, dep + 1);
	dfs((sum + a[dep]) % mod, dep + 1);
}

void dfs2(int sum, int dep)
{	
	if(dep == n) 
	{
		int tmp = lower_bound(b, b + tot, (mod - sum)) - b - 1;		
		ret = max(ret, (b[tmp] + sum) % mod);
		ret = max(ret, (b[tot] + sum) % mod);
		return ;
	}
	dfs2(sum, dep + 1);
	dfs2((sum + a[dep]) % mod, dep + 1);	
}

int main()
{
	scanf("%lld%lld", &n, &mod);
	for(int i = 0; i < n; i++) 
		scanf("%lld", &a[i]);

	sort(b, b + tot);
	dfs2(0, (n >> 1) + 1);

	printf("%lld\n", ret);
	return 0;
}