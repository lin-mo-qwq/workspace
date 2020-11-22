#include<bits/stdc++.h>
using namespace std;
#define M (int)(5e5 + 5)
#define INF (int)(-5e8 - 5)
typedef long long ll;

inline int read()
{
	register int ret = 0, c = getchar(), b = 1;
	while(!isdigit(c))	b = c == '-'?-1:1,c = getchar();
	while(isdigit(c))	ret = ret * 10 + c - '0', c = getchar();
	return ret * b;
}

struct tree2
{
	tree2 *lson, *rson;
	ll lazy, x, past;
} dizhi[M << 2], *root = &dizhi[0];

int n, m, a[M], t;

void pushdown(tree2 *tree, int l, int r)
{
	if(!tree->lazy) return;

	int mid = (l + r) / 2;

	tree->lson->x += tree->lazy * (mid - l + 1);
	tree->rson->x += tree->lazy * (r - mid);
	tree->lson->lazy += tree->lazy;
	tree->rson->lazy += tree->lazy;
	tree->lazy = 0;
}

void update(tree2* tree)
{
 	tree->x = tree->lson->x + tree->rson->x;
}

void addpoint(tree2 *tree)
{
	tree->lson = &dizhi[++t];
	tree->rson = &dizhi[++t];
}

void build(tree2 *tree, int l, int r)
{
	if(l == r)
	{
		tree->past = tree->x = a[l];
		return;
	}
	int mid = (l + r) / 2;
	addpoint(tree);
	build(tree->lson, l, mid);
	build(tree->rson, mid + 1, r);
	update(tree);
}

void add(tree2 *tree, int l, int r, int x, int y, int d)
{
	if(x <= l && y >= r)
	{
		tree->x += (ll)d * (r - l + 1);
		tree->past = max(tree->x, tree->past);
		tree->lazy += d;
		return;
	}
	pushdown(tree, l, r);
	int mid = (l + r) / 2;
	if (x <= mid)	add(tree->lson, l, mid, x, y, d);
	if (y > mid)	add(tree->rson, mid + 1, r, x, y, d);
	update(tree); 
}

void change(tree2 *tree, int l, int r, int x, int y, int d)
{
	if(l == r && x <= l && y >= r)
	{
		tree->x = min(tree->x, (ll)d);
		tree->past = max(tree->x, tree->past);
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid) change(tree->lson, l, mid, x, y, d);
	if(y > mid) change(tree->rson, mid + 1, r, x, y, d);
	update(tree);
}

ll query(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r)
		return tree->x;
	pushdown(tree, l, r);
	int mid = (l + r) / 2;
	ll t1 = 0, t2 = 0;
	if (x <= mid) t1 = query(tree->lson, l, mid, x, y);
	if (y > mid) t2 = query(tree->rson, mid + 1, r, x, y);
	return t1 + t2;
}

ll findmax(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r)	
		return tree->x;
	int mid = (l + r) / 2;
	ll t1 = INF, t2 = INF;
	if(x <= mid) t1 = findmax(tree->lson, l, mid, x, y);
	if(y > mid) t2 = findmax(tree->rson, mid + 1, r, x, y);
	return max(t1, t2);
}

ll findpast(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r)	
		return tree->past;
	int mid = (l + r) / 2;
	ll t1 = INF, t2 = INF;
	if(x <= mid) t1 = findpast(tree->lson, l, mid, x, y);
	if(y > mid) t2 = findpast(tree->rson, mid + 1, r, x, y);
	return max(t1, t2);
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++) 
		cin>>a[i];
	build(root, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int op;
		cin>>op;
		switch(op)
		{
			int l, r, k;
			case 1:
				cin>>l>>r>>k;
				add(root, 1, n, l, r, k); break;
			case 2:
				cin>>l>>r>>k;
				change(root, 1, n, l, r, k); break;
			case 3:
				cin>>l>>r;
				cout<<query(root, 1, n, l, r)<<endl; break;
			case 4:
				cin>>l>>r;
				cout<<findmax(root, 1, n, l, r)<<endl; break;
			case 5:
			 	cin>>l>>r;
				cout<<findpast(root, 1, n, l, r); break;
		}
	}
	return 0;
}