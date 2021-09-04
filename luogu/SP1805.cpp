#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, h[100005], ans;

struct rect
{
	ll h, w;

	rect(ll _h, ll _w) : h(_h), w(_w) {}

	ll calc()
	{
		return h * w;
	}
};

stack<rect> s;

void push(rect x)
{

	rect tep(0, 0);

	while(!s.empty())
	{
		if(x.h >= s.top().h)
			break;

		tep.h = s.top().h;
		tep.w += s.top().w;

		ans = max(ans, tep.calc());

		s.pop();
	}

	s.push((rect){x.h, tep.w + 1});
}

void memset()
{
	n = 0;
	ans = 0;

	memset(h, 0, sizeof(h));

	while(!s.empty())
		s.pop();
}

void work()
{

	cin >> n;

	if (n == 0)
		exit(0);

	for (int i = 1; i <= n; i++)
		cin >> h[i], push((rect){h[i], 1});
	push((rect){0, 1});
}

int main()
{
	while (1)
	{
		work();
		cout << ans << endl;
		memset();
	}
	return 0;
}