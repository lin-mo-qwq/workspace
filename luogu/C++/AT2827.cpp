#include<bits/stdc++.h>
using namespace std;
int n, ret[100005], f[100005], maxnum, ans; 

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int c)
{
	for(int i = x; i <= maxnum; i += lowbit(i)) f[i] = max(f[i], c);
}

int query(int x)
{
	int res = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) res = max(res, f[i]);
	return res;
}

int main()
{
    cin>>n;
	for(int i = 1; i <= n; i++)
	    cin>>ret[n], maxnum = max(ret[n], maxnum);
	for(int i = 1, tmp; i <= n; i++)
		tmp = query(ret[i]) + 1, add(ret[i], tmp), ans = max(ans, tmp);	
	cout<<ans<<endl; 
	return 0;
}