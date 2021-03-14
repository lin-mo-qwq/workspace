#include<bits/stdc++.h>
using namespace std;
#define M 25
long long A[M], B[M], ans = 1, n;

int cnt_bigger(int x)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(B[i] >= x) cnt++;
	return cnt;
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>A[i];
	for(int i = 1; i <= n; i++) cin>>B[i];
	sort(A + 1, A + 1 + n);
	for(int i = 1; i <= n; i++)
		ans *= cnt_bigger(A[i]) - (n - i);
	cout<<ans<<endl;
	return 0;
}