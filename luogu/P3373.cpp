#include <bits/stdc++.h>
#define ll long long
#define M 100005

using namespace std;

struct tree2
{
	tree2 *lson, *rson;
	ll x, mlazy = 1, alazy;
} dizhi[M << 1], *root = &dizhi[0];

int a[M], n, m, P = 1, t = 1;

void build(tree2 *tree, int l, int r)
{
	if (l == r)
	{
		tree->x = a[l];
		return;
	}

	int mid = (l + r) / 2;

	tree->lson = &dizhi[t++];
	tree->rson = &dizhi[t++];

	build(tree->lson, l, mid);
	build(tree->rson, mid + 1, r);

	tree->x = (tree->lson->x + tree->rson->x) % P;
}

void pushdown(tree2 *tree, int l, int r)
{
	if ((tree->alazy == 0 && tree->mlazy == 1) || (tree->lson == nullptr))
		return;

	int mid = (l + r) / 2;

	tree->lson->x = (tree->lson->x * tree->mlazy + (ll)tree->alazy * (mid - l + 1)) % P;
	tree->rson->x = (tree->rson->x * tree->mlazy + (ll)tree->alazy * (r - mid)) % P;
	tree->lson->mlazy = (tree->mlazy * tree->lson->mlazy) % P;
	tree->rson->mlazy = (tree->mlazy * tree->rson->mlazy) % P;
	tree->lson->alazy = (tree->mlazy * tree->lson->alazy + tree->alazy) % P;
	tree->rson->alazy = (tree->mlazy * tree->rson->alazy + tree->alazy) % P;

	tree->alazy = 0;
	tree->mlazy = 1;
}

void change1(tree2 *tree, int l, int r, int x, int y, int d)
{
	if (x <= l && y >= r)
	{
		if (tree->alazy)
			pushdown(tree, l, r);
		tree->x = (tree->x * d) % P;
		tree->mlazy = (tree->mlazy * d) % P;
		return;
	}

	pushdown(tree, l, r);

	int mid = (l + r) / 2;

	if (x <= mid)
		change1(tree->lson, l, mid, x, y, d);
	if (y > mid)
		change1(tree->rson, mid + 1, r, x, y, d);

	tree->x = (tree->lson->x + tree->rson->x) % P;
}

void change2(tree2 *tree, int l, int r, int x, int y, int d)
{
	if (x <= l && y >= r)
	{
		tree->x = (tree->x + d * (r - l + 1)) % P;
		tree->alazy = (tree->alazy + d) % P;
		return;
	}

	pushdown(tree, l, r);

	int mid = (l + r) / 2;

	if (x <= mid)
		change2(tree->lson, l, mid, x, y, d);
	if (y > mid)
		change2(tree->rson, mid + 1, r, x, y, d);

	tree->x = (tree->lson->x + tree->rson->x) % P;
}

ll query(tree2 *tree, int l, int r, int x, int y)
{
	if (x <= l && y >= r)
		return tree->x;

	pushdown(tree, l, r);

	int mid = (l + r) / 2;

	ll t1 = 0, t2 = 0;

	if (x <= mid)
		t1 = query(tree->lson, l, mid, x, y);
	if (y > mid)
		t2 = query(tree->rson, mid + 1, r, x, y);

	return (t1 + t2) % P;
}

int main()
{
	cin >> n >> m >> P;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(root, 1, n);

	for (int i = 1; i <= m; i++)
	{
		int opt;
		cin >> opt;
		if (opt == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			change1(root, 1, n, x, y, k);
		}
		else if (opt == 2)
		{
			int x, y, k;
			cin >> x >> y >> k;
			change2(root, 1, n, x, y, k);
		}
		else
		{
			int x, y;
			cin >> x >> y;
			cout << query(root, 1, n, x, y) << endl;
		}
	}
	return 0;
}