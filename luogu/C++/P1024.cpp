#include<bits/stdc++.h>
using namespace std;

int cnt=0;
double a,b,c,d;

double fc(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}

void work()
{
	for(double i=-100.00;i<=100.00;i+=0.001)
	{
		double l=i,r=i+0.001;
		if(fc(l)*fc(r)<0)
			printf("%.2lf ",l),cnt++;
		if(cnt==3)
			break;
	}
}

int main()
{
	cin>>a>>b>>c>>d;
	work();
	return 0;
}