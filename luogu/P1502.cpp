#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=100005;
const ll MAXINT=2147482647LL;
#define clr(x) memset(x,0,sizeof(x))

struct tree2
{
	tree2 *lson,*rson;
	int lazy,x;
} dizhi[M<<3],*root=&dizhi[0];

int t,w,h,n,ans,T;

void pushdown(tree2 *tree,int l,int r)
{
	if(!tree->lazy) return ;

	tree->lson->x+= tree->lazy;
	tree->rson->x+= tree->lazy;
	tree->lson->lazy+=tree->lazy;
	tree->rson->lazy+=tree->lazy;
	tree->lazy=0;
}


void add(tree2 *tree,int l,int r,int x,int y,int d)
{
	if(x<=l&&y>=r)
	{
		tree->x+=d;
		tree->lazy+=d;
		return ;
	}
	
	if(tree->lson==NULL)
	{
		tree->lson=&dizhi[++t];
		tree->rson=&dizhi[++t];
	}

	pushdown(tree,l,r);
	
	int mid=(l+r)/2;

	if(x<=mid)	add(tree->lson,l,mid,x,y,d);
	if(y>mid)	add(tree->rson,mid+1,r,x,y,d);

	tree->x=max(tree->lson->x,tree->rson->x);
}

struct point
{
	int x,y,l;
	friend bool operator <(point a,point b)
	{
		return a.x<b.x;
	}

	void inp()
	{
		cin>>x>>y>>l;
	}
}a[M<<1];

void inp(int i)
{
	a[i*2-1].inp();
	a[i*2].x=min((ll)a[i*2-1].x+w,MAXINT),a[i*2].y=a[i*2-1].y,a[i*2].l=-a[i*2-1].l;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>w>>h;
		ans=0,clr(dizhi),t=0;
		for(int i=1;i<=n;i++)
			inp(i);
		sort(a+1,a+2*n+1);
		for(int i=1;i<=n*2;i++)
		{
			add(root,1,MAXINT,a[i].y,min((ll)a[i].y+h-1,MAXINT),a[i].l);
			if(a[i+1].x!=a[i].x)
				ans=max(ans,root->x);
		}
		cout<<ans<<endl;
	}
	return 0;
}