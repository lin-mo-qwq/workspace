#include <bits/stdc++.h>
using namespace std;
extern "C" int Seniorious(int);

extern "C" int Chtholly(int n, int OvO)
{
	int ans = 1;
	int l=1,r=n+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(Seniorious(mid)>=0)
			r=(ans=mid)-1;
		else
			l=mid+1;
	} 
	return ans;
}