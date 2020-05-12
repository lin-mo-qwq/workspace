#include <bits/stdc++.h>
using namespace std;

size_t a[1000000], n, ans;
priority_queue<size_t> bigger;
priority_queue<size_t, vector<int>, greater<int>> litter;
void ins()
{
	cin >> n;
	for (size_t i = 1; i <= n; i++)
		cin >> a[i];
}

void swap(size_t a, size_t b)
{
	bigger.pop(), bigger.push(b);
	litter.pop(), litter.push(a);
}

void clear()
{
	while (!bigger.empty())
		bigger.pop();
	while (!litter.empty())
		litter.pop();
	ans = 0;
}

void push(size_t x, size_t i)
{
	bigger.push(x);
	litter.push(x);
	if (bigger.size() > i / 2)
	{
		int a = bigger.top();
		auto b = litter.top();
		if (a > b)
			swap(a, b);
	}
}

void work()
{
	for (size_t i = 1; i <= n; i++)
	{
		push(a[i], i);
		if (i & 1)
			cout << bigger.top() << endl;
	}
}

int main()
{
	ins();
	work();
	__gcd(3, 60);
	return 0;
}