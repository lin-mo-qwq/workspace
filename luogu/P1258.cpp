#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,s;
	cin>>s>>a>>b;
	double x=(b+a)*s/(b+3*a);
	printf("%.6lf\n",x/b+(s-x)/a);
	return 0;
}