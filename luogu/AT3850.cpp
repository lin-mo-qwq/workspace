#include<bits/stdc++.h>
using namespace std;

int prise[100006],f[100006];
bool isprise[100006];// isprise[] 用来判定一个数是否是素数

void os(int r)// 欧拉筛法
{
	int tot=0;
	memset(isprise,1,sizeof(isprise));//初始化都是素数
	isprise[1]=isprise[0]=0;// 0和1不是素数，首先排除
	for(int i=2;i<=r;i++)
	{
		if(isprise[i])// 当它为素数时
			prise[tot++]=i;// 记录素数 ， pirse[] 是一个素数表存放着我们目前筛出的所有素数
		for(int j=0;i*prise[j]<=r;j++)
		{
			isprise[i*prise[j]]=0;//用最小素因子晒去每个和数
			if(i%prise[j]==0)//当 i 为 prise[j] 的倍数时，prise[j] 已为最小素因子 
				break;// 直接跳出 ， 这是欧拉筛法能维持O(n)复杂度的关键。
		}
	}
}

void Prefix_and()//前缀和
{
	for(int i=2;i<=100005;i++)
	{
		if(isprise[i]&&isprise[(i+1)/2])//当这个数为2017数时
			f[i]=f[i-1]+1;//f[x] 为 由1~x 的2017数的个数 。 当x为 2017 数时 ， f[x] 就为 f[x-1] 也就是在 1~x-1 的2017数的个数加一
		else
			f[i]=f[i-1];// 否则， 它就为  1~前一个数 的2017数的个数。
	}
}

int main()
{
	int n,x,y;
	os(100005);
	Prefix_and();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		cout<<f[y]-f[x-1]<<endl;//输出答案。
	}
	return 0;
}