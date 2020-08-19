#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> sums;

int main()
{
	ll n, k;

	cin>>n>>k;
	sums.push_back(1);
	if(n!=1) sums.push_back(n);
	for(int i = 2; i <= sqrt(n); i++)
		if(n%i == 0)
		{
			sums.push_back(i);
			if(n/i!=i)	sums.push_back(n/i);
		}

	sort(sums.begin(),sums.end());

	if(k<=sums.size()) cout<<sums[k-1]<<endl;
	else cout<<"-1"<<endl;
 	return 0;
}