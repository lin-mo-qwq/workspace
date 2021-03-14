#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, E = 0, O = 0;
	cin>>n;
	for(int i = 1, ret; i <= n; i++)
		cin>>ret, ret % 2 == 0 ? E++ : O++;
	while(O > E) O -= 2, E++;
	if(E > O + 1) E = O + 1;
	cout<<E + O<<endl;
	return 0;
}	