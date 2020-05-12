#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dad[10000];



int find(int x)
{
	if(dad[x]) return dad[x]=find(x);
	return x;
}

int main()
{
	int a,b;
	cin>>a>>b;
	return 0;
}