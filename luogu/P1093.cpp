#include<bits/stdc++.h>
using namespace std;

int n;

struct student
{
	int math,english,chinese,score,num;

	void ins(int _num)
	{
		cin>>chinese>>math>>english;
		score=chinese+math+english;
		num=_num;
	}

	friend bool operator <(student a,student b)
	{	
		if(a.score!=b.score)
			return a.score>b.score;

		if(a.chinese!=b.chinese)
			return a.chinese>b.chinese;

		return a.num<b.num;
	}
	
}a[400];

void inp()
{
	cin>>n;

	for(int i=1;i<=n;i++)
		a[i].ins(i);
	
}

void work()
{
	sort(a+1,a+1+n);

	for(int i=1;i<=5;i++)
		cout<<a[i].num<<' '<<a[i].score<<endl;
}

int main()
{
	inp();
	work();
	return 0;
}