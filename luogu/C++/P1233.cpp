#include<bits/stdc++.h>
using namespace std;

#define M 5005
int n, f[M], ans;

struct wood
{
	int w, l;
	friend bool operator < (wood a, wood b)
	{
		if(a.l == b.l) return a.w > b.w;
		return a.l > b.l;
	}
} a[M];

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i].l>>a[i].w, f[i] = 1;
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(a[i].w > a[j].w) f[i] = max(f[j] + 1, f[i]);
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout<<ans<<endl;
	return 0;
}