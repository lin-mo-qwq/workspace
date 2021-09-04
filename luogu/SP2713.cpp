#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#define M 100005
#define clr(x) memset(x, 0, sizeof(x))
typedef long long ll;


struct tree2
{
	tree2 *lson, *rson;
	ll max, sum;
} dizhi[M << 1],*root = &dizhi[0];

ll n, m, t, a[M];

void update(tree2 *tree)
{
	tree->max = max(tree->lson->max, tree->rson->max);
	tree->sum = tree->lson->sum + tree->rson->sum;
}

void build(tree2 *tree, int l, int r)
{
	if(l == r)
	{
		tree->max = tree->sum = a[l];
		return ;
	}

	int mid = (l + r) / 2;

	tree->lson = &dizhi[++t];
	tree->rson = &dizhi[++t];

	build(tree->lson, l, mid);
	build(tree->rson, mid + 1, r);
	update(tree);
}

void change(tree2 *tree, int l, int r, int x, int y)
{
	if(l == r && x <= l && y >= r)
	{
		tree->max = tree->sum = sqrt(tree->sum);
		return ;
	}

	int mid = (l + r) / 2;

	if(x <= mid && tree->max > 1)	change(tree->lson, l, mid, x, y);
	if(y > mid && tree->max > 1)	change(tree->rson, mid + 1, r, x, y);

	update(tree);
}

ll query(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r)
		return tree->sum;
	
	int mid=(l+r)/2;

	ll t1 = 0,t2 = 0;

	if(x <= mid)	t1 = query(tree->lson, l, mid, x, y);
	if(y > mid) t2 = query(tree->rson, mid + 1, r, x, y);

	return t1 + t2;
}

int main()
{
	
	ios::sync_with_stdio(false);

	int cnt = 0;

	while(cin>>n)
	{
		clr(dizhi), clr(a);
		
		t = 0;

		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		build(root,1,n);

		printf("Case #%d:\n", ++cnt);

		cin>>m;

		for(int i = 1; i <= m; i++)
		{
			ll k, l, r;
			cin>>k>>l>>r;

			if(l > r)
				swap(l, r);

			if(k == 0)	change(root, 1, n, l, r);
			else	printf("%lld\n\n", query(root, 1, n, l, r));
		}
	}	
	return 0;
}