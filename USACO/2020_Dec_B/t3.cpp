#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, x[N], y[N], cow[N];
char dir[N];

struct Intersecition
{
	int i, j, time_i, time_j, active;
};

Intersecition I[N * N];

void find_all_Intersecition(void)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(dir[i] == dir[j]) continue;
			int xi = x[i], xj = x[j], yi = y[i], yj = y[j];
			if(dir[i] == 'E') 
				swap(xi, yi), swap(xj, yj);
			
			if(yi > yj) continue;
			if(xi < xj) continue;
			if(xi >= xj + yj - yi) continue;

			Intersecition Inew = {i, j, yj - yi, xi - xj, 1};
			I[++cnt] = Inew;
		}
}

int main(void)
{
	cin>>n;
	for(int i = 1; i <= n; i++) 
		cin>>dir[i]>>x[i]>>y[i];
	find_all_Intersecition();
	
	while(1)
	{
		int earl = -1;
		for(int i = 1; i <= N * N; i++)
			if(I[i].active)
				if(earl == -1 || I[i].time_i < I[earl].time_i) earl = i;
		if(earl == -1) break;
		Intersecition &E = I[earl];
		if(cow[E.i] == 0 && (cow[E.j] == 0 || cow[E.j] > E.time_j))
			cow[E.i] = E.time_i;
		E.active = 0;
	}

	for(int i = 1; i <= n; i++)
		if(cow[i] == 0) cout<<"Infinity"<<endl;
		else cout<<cow[i]<<endl;
	return 0;
}