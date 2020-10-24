#include<iostream>
using namespace std;

#define M 100005

struct trian
{
	bool isbus;
	int time;
	int mon;
	void inp()
	{ cin >> isbus >> mon >> time;}
} T[M];

int n, ans, root = 1, last;
trian Y[M];

int main()
{
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		T[i].inp();
		if(!T[i].isbus)  Y[++last] .time= T[i].time + 45, Y[last].mon = T[i].mon;
		else
		{
			for(int j = root; Y[j].time < T[i].time && root <= last; j = ++root);
			for(int j = root; j <= last; j++)
				if(Y[j].mon >= T[i].mon) 
				{
					T[i].mon = Y[j].mon = 0;
					break;
				}
		}
		ans += T[i] . mon;		
	}

	cout << ans << endl;
	return 0;
}
