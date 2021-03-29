#include<bits/stdc++.h>
using namespace std;
int n, ans;
const int M = 1e5 + 5;
struct Ret
{
	int res, index; 
	friend bool operator < (Ret a, Ret b)
	{
		return a.res < b.res || (a.res == b.res && a.index < b.index);
	}
} ret[M];

int main()
{
	freopen("sort.in", "r", stdin);		
	freopen("sort.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &ret[i].res), ret[i].index = i;
	sort(ret + 1, ret + 1 + n);
	for(int i = 1; i <= n; i++)
		ans = max(ans, ret[i].index - i);
	printf("%d\n", ans + 1);
	return 0;
}