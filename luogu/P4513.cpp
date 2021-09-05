#include<bits/stdc++.h>
using namespace std;

#define M 500005

struct tree2
{
	tree2 *lson,*rson;
	int ml,mr,mx,sum;
} dizhi[M<<1],*root=&dizhi[0];

int n,m,a[M],t,pt;

void update(tree2 *tree,tree2 *lson,tree2 *rson)
{
	tree->sum=lson->sum+rson->sum;
	tree->ml=max(lson->ml,lson->sum+rson->ml);
	tree->mr=max(rson->mr,rson->sum+lson->mr);
	tree->mx=max(lson->mr+rson->ml,max(lson->mx,rson->mx));
}

void build(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->sum=tree->ml=tree->mr=tree->mx=a[l];
		return ;
	}

	int mid=(l+r)/2;

	tree->lson=&dizhi[++t];
	tree->rson=&dizhi[++t];

	build(tree->lson,l,mid);
	build(tree->rson,mid+1,r);

	update(tree,tree->lson,tree->rson);
}

tree2* query(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
		return tree;
	int mid=(l+r)/2;
	tree2 *t1=NULL,*t2=NULL;
	if(x<=mid)	t1=query(tree->lson,l,mid,x,y);
	if(y>mid)	t2=query(tree->rson,mid+1,r,x,y);
	if(t1==NULL)	return t2;
	if(t2==NULL)	return t1;
	tree2 *tmp=&dizhi[++t];
	update(tmp,t1,t2);
	return tmp;
}

void change(tree2 *tree,int l,int r,int x,int d)
{
	if(l==r)
	{
		tree->sum=tree->ml=tree->mr=tree->mx=d;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)	change(tree->lson,l,mid,x,d);
	else	change(tree->rson,mid+1,r,x,d);
	update(tree,tree->lson,tree->rson);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	build(root,1,n);
	pt=t;
	for(int i=1;i<=m;i++)
	{
		int opt;
		cin>>opt;
		if(opt==1)
		{
			int a,b;
			cin>>a>>b;
			if(a>b)	swap(b,a);
			t=pt;
			cout<<query(root,1,n,a,b)->mx<<endl;
		}
		else
		{
			int p,s;
			cin>>p>>s;
			change(root,1,n,p,s);
		}
	}
	return 0;
}