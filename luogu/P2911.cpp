#include<bits/stdc++.h>
using namespace std;

struct data
{
	int key;
	int frequency;
	void ins(int _key)
	{
		key=_key;
	}
	void plus()
	{
		frequency++;
	}
	friend bool operator < (data a,data b)
	{
		if(a.frequency==b.frequency)
			return a.key<b.key;
		return a.frequency>b.frequency;
	}
} a[100];


int s1,s2,s3;

void work()
{
	cin>>s1>>s2>>s3;

	for(int i=1;i<=s1;i++)
		for(int j=1;j<=s2;j++)
			for(int k=1;k<=s3;k++)
				a[i+j+k].ins(i+j+k),a[i+j+k].plus();
	sort(a,a+s1+s2+s3);
	cout<<a[0].key<<endl;
}

int main()
{
	work();
	return 0;
} 
