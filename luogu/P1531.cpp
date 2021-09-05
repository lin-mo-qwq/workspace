#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define M 200005

struct tree2
{
	tree2 *lson, *rson;
	ll x, mx;
} dizhi[M << 1], *root = &dizhi[0];

int n, m, t;
ll a[M];

void up(tree2 *tree)
{
	tree->x = tree->lson->x + tree->rson->x;
	tree->mx = max(tree->lson->mx, tree->rson->mx);
}

void build(tree2 *tree, int l, int r)
{
	if(l == r)
	{
		tree->x = tree->mx = a[l];
		return ;
	}

	int mid = (l + r) / 2;

	tree->lson = &dizhi[++t];
	tree->rson = &dizhi[++t];

	build(tree->lson, l, mid);
	build(tree->rson, mid + 1, r);

	up(tree);
}

void change(tree2 *tree, int l, int r, int x, ll y)
{
	if(l == r)
	{
		tree->x = tree->mx = y;
		return ;
	}

	int mid = (l + r) / 2 ;

	if(x <= mid)	change(tree->lson, l, mid, x, y);
	else	change(tree->rson, mid + 1, r, x, y);

	up(tree);
}

ll query(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r)	return tree->mx;

	int mid = (l + r) / 2;

	ll lson = 0, rson = 0;

	if(x <= mid) lson = query(tree->lson, l, mid, x, y);
	if(y > mid) rson = query(tree->rson, mid + 1, r, x, y);

	return max(lson, rson);
}

int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	build(root, 1, n);

	for(int i = 1, l, r; i <= m; i++)
	{
		char c;
		cin >> c >> l >> r;

		if(c == 'Q')
			cout << query(root, 1, n, l, r) << endl;
		else
		{
			if(query(root, 1, n, l, l) < r)
				change(root, 1, n, l, r);
		}
	}
	return 0;
}