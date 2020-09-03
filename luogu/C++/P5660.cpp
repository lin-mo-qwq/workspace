#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cnt = 0;
	string a;
	cin >> a;
	for(int i = 0; i < a.size(); i++)
		if(a[i] - '0') cnt++;
	cout<<cnt;
	return 0;
}
