#include<bits/stdc++.h>
using namespace std;

#define M 100005

bool isprise[M];
int a[M],prise[M];

void find(int r)
{
	int tot=0;
	memset(isprise,1,sizeof(isprise));
	for(int i=2;i<=r;i++)
	{
		if(isprise[i])
			prise[tot++]=i;
		for(int j=0;i*prise[j]<=r;j++)
		{
			isprise[i*prise[j]]=0;
			if(i%prise[j]==0)
				break;
		}
	}
	isprise[1]=false;
}

int main()
{
	int n;
	
	cin>>n;
	
	n<=2?cout<<1<<endl:cout<<2<<endl;
	
	find(n+1);

	for(int i=1;i<=n;i++)
		isprise[i+1]?cout<<1<<' ':cout<<2<<' ';
	
	puts("");
	return 0;
}