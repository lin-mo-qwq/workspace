#include<bits/stdc++.h>
using namespace std;

int ret[1001], n, f1[1001], f2[1001], ans;

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)	cin>>ret[i], f1[i] = 1;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(ret[i] > ret[j]) f1[i] = max(f1[i], f1[j] + 1);
	for(int i = n; i >= 1; i--)
		for(int j = n; j > i; j--)	
			if(ret[i] > ret[j]) f2[i] = max(f2[i], f2[j] + 1);
	
	for(int i = 1; i <= n; i++) ans = max(ans, f1[i] + f2[i]);

	cout<< n - ans;
	return 0;
}