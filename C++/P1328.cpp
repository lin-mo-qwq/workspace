#include<bits/stdc++.h>
using namespace std;

queue <int> A, B;
int n, na, nb, ansa, ansb;
int score[6][6]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}}; 

int main()
{

	cin>>n>>na>>nb;

	for (int i=1; i<=na; i++)
	{
		int x;
		cin>>x, A.push(x);
	}

	for (int i=1; i<=nb; i++)
	{
		int x;
		cin>>x, B.push(x);
	}

	for (int i=1; i<=n; i++)
	{
		int a = A.front(), b = B.front();

		if(score[a][b])
			ansa++;
		if(score[b][a])
			ansb++;

		A.pop(), A.push(a), B.pop(), B.push(b);
	}

	cout<<ansa<<' '<<ansb<<endl;

	return 0;
}