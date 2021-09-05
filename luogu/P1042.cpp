#include<bits/stdc++.h>
using namespace std;

int m[]={11,21};
short a[25*5000];
int n=0;

void work()
{
	char score;
	while(1)
	{
		cin>>score;	
		if(score=='E') break;
		else if(score=='W') a[n++]=1;
		else  a[n++]=0;
	}
	for(int i=0;i<2;i++)
	{
		int l=0,w=0;
		for(int j=0;j<n;j++)
		{
			w+=a[j],l+=1-a[j];
			if(max(w,l)>=m[i]&&abs(w-l)>=2)
				printf("%d:%d\n",w,l),w=l=0;
		}
		printf("%d:%d\n\n",w,l);
	}
}

int main()
{
	work();
	return 0;
}