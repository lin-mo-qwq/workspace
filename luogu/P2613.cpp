#include<bits/stdc++.h>
using namespace std;

#define Mod 19260817
typedef long long ll;

inline ll read()
{
	register ll ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=(ret*10+c-'0')%Mod,c=getchar();
	return (ret*b) % Mod;
}

void exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return ;
	}	
	
	ll q = a / b, r = a % b;
	exgcd(b, r, x, y);
	ll t = x; x = y;
	y = t - q * y;
}

int main()
{
	ll a, b, x, y;
	
	a = read();
	b = read();

	a %= Mod;
	b %= Mod;

	if(b % Mod == 0)
		cout << "Angry!" << endl, exit(0);
	
	exgcd(b, Mod, x, y);

	x = (x % Mod + Mod) % Mod;

	cout << a * x % Mod <<endl;
	return 0;
}