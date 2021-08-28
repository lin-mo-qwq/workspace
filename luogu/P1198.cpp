#include<bits/stdc++.h>
using namespace std;

#define M 200005
typedef long long ll;

int n, mod, t, past, len;

struct tree2
{
	tree2 *lson, *rson;
	ll x, maxx;
} dizhi[M << 1], *root = &dizhi[0];

void update(tree2 *tree)
{
	tree->x = tree->lson->x + tree->rson->x;
	tree->maxx = max(tree->lson->maxx, tree->rson->maxx) % mod;
}
 
void build(tree2 *tree)
{
	tree->lson = &dizhi[++t];
	tree->rson = &dizhi[++t];
	tree->lson->x = tree->lson->maxx = tree->rson->x = tree->rson->maxx = 0;
}

void insert(tree2 *tree, int l, int r, int x, ll d)
{	
	if(l == r)
	{
		tree->x = tree->maxx = d;
		return ;
	}
	
	if(tree->lson == NULL) build(tree);

	int mid = (l + r) / 2;

	if(x <= mid)	insert(tree->lson, l, mid, x, d);
	else insert(tree->rson, mid+1, r, x, d);

	update(tree);	
}

ll query(tree2 *tree, int l, int r, int x, int y)
{	
	if(x <= l && y >= r)	return tree->maxx;

	int mid = (l + r) / 2;

	ll t1 = 0, t2 = 0;

	if(x <= mid) t1 = query(tree->lson, l, mid, x, y);
	if(y > mid) t2 = query(tree->rson, mid+1, r, x, y);

	return max(t1, t2) % mod;
}

int main()
{
	cin >> n >> mod;

	for(int i = 1, ret; i <= n; i++)
	{
		char c;
		cin >> c >> ret;
		if(c == 'Q')
			cout << (past = query(root, 1, M, len - ret + 1, len) % mod) << endl;
		else
			insert(root, 1, M, ++len, (ret + past) % mod);
	}
	return 0;
}