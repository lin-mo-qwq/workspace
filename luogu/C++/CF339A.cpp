#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a[10005],cnt=1;

	while(~scanf("%d+",&a[cnt++]));
	sort(a+1,a+cnt-1);
	for(int i=1;i<cnt-2;i++)
		cout<<a[i]<<'+';
	cout<<a[cnt-2];
	return 0;
}