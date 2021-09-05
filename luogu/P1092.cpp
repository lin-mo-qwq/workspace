#include<bits/stdc++.h>
using namespace std;

#define M 35

char a[M], b[M], c[M];
int n, t[300], use[M], p[M], u[M], cnt; 

bool check()
{
	for(int i = n; i >= 1; i--)
	{
		if(t[a[i]] == -1|| t[b[i]] == -1 || t[c[i]] == -1) continue;
		if((t[a[i]] + t[b[i]]) % n != t[c[i]])
			if((t[a[i]] + t[b[i]] + 1) % n != t[c[i]]) return false;
	}
	return true;
}

void puts()
{
	int add = 0;
	for(int i = n; i >= 1; i--)
	{
		int s = t[a[i]] + t[b[i]] +add;
		if(s % n != t[c[i]]) return ;
		add = s / n;
	}

	cout << t['A'] << ' ';

	for(int i = 'A' + 1; i <= 'A' + n - 1; i++) 
		cout << t[i] << ' ';
	cout << endl;
	exit(0);
}

void dfs(int x)
{
	if(x > n)
	{
		puts();
		return ;
	}

	for(int i = n - 1; i >= 0; i--)
	{
		if(use[i])	continue;
		t[p[x] + 'A' - 1] = i;
		if(check())
		{
			use[i] = 1;
			dfs(x + 1);
			use[i] = 0;
		}
	}

	t[p[x] + 'A' - 1]=-1;
}

int main(void)
{
	memset(t, -1, sizeof(t));
	scanf("%d", &n);
	scanf("%s%s%s", a + 1, b + 1, c + 1);
	for(int i = n; i >= 1; i--)
	{
		if(!u[a[i] - 'A' + 1]) p[++cnt] = a[i] - 'A' + 1, u[a[i] - 'A' + 1] = 1;
		if(!u[b[i] - 'A' + 1]) p[++cnt] = b[i] - 'A' + 1, u[b[i] - 'A' + 1] = 1; 
		if(!u[c[i] - 'A' + 1]) p[++cnt] = c[i] - 'A' + 1, u[c[i] - 'A' + 1] = 1; 
	}
	dfs(1);
	return 0;
}