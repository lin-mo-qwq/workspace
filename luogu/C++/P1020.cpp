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
	while(cin>>ret[++n]) maxnum = max(ret[n], maxnum);
	n--;
	for(int i = n, tmp; i >= 1; i--)
		tmp = query(ret[i]) + 1, add(ret[i], tmp), ans = max(ans, tmp);	
	cout<<ans<<endl; 
	memset(f, 0, sizeof(f)); ans = 0;
	for(int i = 1, tmp; i <= n; i++)
		tmp = query(ret[i] - 1) + 1, add(ret[i], tmp), ans = max(ans, tmp);	
	cout<<ans<<endl;
	return 0;
}