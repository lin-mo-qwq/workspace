#include<bits/stdc++.h>
using namespace std;

int a[10005]={6}, n, c[10] = {6,2,5,5,4,5,6,3,7,6}, ans;

int main()
{
	cin>>n;
	for(int i = 1, j = i; i <= 3450; j = ++i)
	{
		while(j >= 1)
			a[i] += c[j % 10],	j /= 10;
	}
	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			if(a[i] + a[j] + a[i + j] + 4 == n) ans++;
	cout<<ans<<endl;
	return 0;
}