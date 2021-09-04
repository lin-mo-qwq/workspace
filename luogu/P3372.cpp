#include<bits/stdc++.h>

#define ll long long

using namespace std;

#define M 500005

struct tree2
{
	tree2 *lson,*rson;
	ll x,lazy;
} dizhi[M << 1], *root=&dizhi[0];

int n,m,a[M],t = 1;

void pushdown(tree2 *tree,int l,int r)
{
	if(!tree->lazy) return ;

	int mid=(l+r)/2;

	tree->lson->x+= tree->lazy*(mid-l+1);
	tree->rson->x+= tree->lazy*(r-mid);
	tree->lson->lazy+=tree->lazy;
	tree->rson->lazy+=tree->lazy;
	tree->lazy=0;
}

void build(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->x=a[l];
		return ;
	}

	int mid=(l+r)/2;

	tree->lson=&dizhi[t++];
	tree->rson=&dizhi[t++];
	build(tree->lson,l,mid);
	build(tree->rson,mid+1,r);
	tree->x=tree->lson->x+tree->rson->x;
}

void add(tree2 *tree,int l,int r,int x,int y,int d)
{
	if(x<=l&&y>=r)
	{
		tree->x+=(ll)d*(r-l+1);
		tree->lazy+=d;
		return ;
	}
	
	pushdown(tree,l,r);
	
	int mid=(l+r)/2;

	if(x<=mid)	add(tree->lson,l,mid,x,y,d);
	if(y>mid)	add(tree->rson,mid+1,r,x,y,d);

	tree->x=tree->lson->x+tree->rson->x;
}

ll query(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
		return tree->x;
	
	pushdown(tree,l,r);

	int mid=(l+r)/2;

	ll t1 = 0,t2 = 0;

	if(x<=mid)	t1 = query(tree->lson,l,mid,x,y);
	if(y>mid) t2 = query(tree->rson,mid+1,r,x,y);

	return t1+t2;
}

int main()
{

	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cin>>a[i];

	build(root,1,n);

	for(int i=1;i<=m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y,k;
			
			cin>>x>>y>>k;

			add(root,1,n,x,y,k);
		}
		else
		{
			int x,y;
			
			cin>>x>>y;

			cout<<query(root,1,n,x,y)<<endl;
		}
	}
	return 0;
}