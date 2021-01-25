#include<bits/stdc++.h>
using namespace std;
#define M 200005
struct tree2
{
	tree2 *lson, *rson;
	int x, lazy;
} dizhi[M << 1], *root = &dizhi[0]; 
int n, m, a[M], t;

void pushdown(tree2 *tree, int l, int r)
{
	if(!tree->lazy) return ;

	int mid = (l + r) / 2;

	tree->lson->x = (mid - l + 1) - tree->lson->x;
	tree->rson->x = (r - mid) - tree->rson->x; 
	tree->lson->lazy ^= 1;
	tree->rson->lazy ^= 1;
	tree->lazy = 0;
}

void build(tree2 *tree, int l, int r)
{
	if(l == r)
	{
		tree->x = a[l];
		return ;
	}

	int mid = (l + r) / 2;

	tree->lson = &dizhi[++t];
	tree->rson = &dizhi[++t];
	build(tree->lson, l, mid);
	build(tree->rson, mid + 1, r);
	tree -> x = tree->lson->x + tree->rson->x;
}

void add(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r)
	{
		tree->x = (r - l + 1) - tree->x;
		tree->lazy ^= 1;
		return ;
	}

	pushdown(tree, l, r);
	int mid = (l + r) / 2;

	if(x <= mid) add(tree->lson, l, mid, x, y);
	if(y > mid) add(tree->rson, mid + 1, r, x, y);

	tree->x = tree->lson->x + tree->rson->x;
}

int query(tree2 *tree, int l, int r, int x, int y)
{
	if(x <= l && y >= r) return tree->x;
	
	pushdown(tree, l, r);
	int mid = (l + r) / 2;

	int t1 = 0, t2 = 0;
	
	if(x <= mid) t1 = query(tree->lson, l, mid, x, y);
	if(y > mid) t2 = query(tree->rson, mid + 1, r, x, y);
	return t1 + t2;
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin>>c;
		a[i] = c - '0';
	}
	build(root, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int o, l, r;
		cin>>o>>l>>r;
		if(o == 0) add(root, 1, n, l, r);
		else cout<<query(root, 1, n, l ,r)<<endl;
	}
	return 0;
}