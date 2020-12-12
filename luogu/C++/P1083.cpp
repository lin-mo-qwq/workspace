#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int n, m, room[M], d[M], l[M], r[M], diff[M], need[M];
bool check(int x)
{
	memset(diff, 0, sizeof(diff));
	for(int i = 1; i <= x; i++)
	{
		diff[l[i]] += d[i];
		diff[r[i] + 1] -= d[i];
	}
	for(int i = 1; i <= n; i++)
	{
		need[i] = diff[i] + need[i - 1];
		if(need[i] > room[i]) return false;
	}
	return true;
}
int main()
{	
	cin>>n>>m;
	int begin = 1, end = m;
	for(int i = 1; i <= n; i++) cin>>room[i];
	for(int i = 1; i <= m; i++)	cin>>d[i]>>l[i]>>r[i];
	if(check(m)) cout<<0<<endl, exit(0);
	while(begin < end)
	{
		int mid = (begin + end) / 2;
		if(check(mid)) begin = mid + 1;
		else end = mid;
	}
	printf("%d\r\n%d\r\n", -1, begin);
	return 0;
}