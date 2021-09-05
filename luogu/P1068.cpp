#include<bits/stdc++.h>
using namespace std;

int n, m, ans, num;

struct man
{
	int score;
	int name;
	void ins(){cin >> name >> score;}
	friend bool operator <(man a, man b)
	{
		if(a.score == b.score) return a.name > b.name;
		return a.score < b.score;
	}
} ma[5005];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) ma[i].ins();
	sort(ma + 1, ma + 1 + n);
	num = m * 1.5; ans = ma[n - num + 1].score, num = 0;
	for(int i = n; i >= 1; i--) if(ma[i].score >= ans) num++;
	cout << ans << ' ' << num << endl;	
	for(int i = n; i >= n - num + 1; i--)
		cout << ma[i].name << ' ' << ma[i].score <<endl;
	return 0;
}