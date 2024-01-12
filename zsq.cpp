#include<bits/stdc++.h>
using namespace std;
const int N=230,M=5e5+50;

int n;

struct oper
{
	int i,j;
};

struct node
{
	int p[N],q[N],tot,d[N];oper op[M];
	
	void base(int i,int j)
	{
		op[++tot]=(oper){i,j};int val=p[i];
		if(i<j)p[i]=p[i+1],p[i+1]=p[i+2],p[i+2]=val;
		if(i>j)p[i]=p[i-1],p[i-1]=p[i-2],p[i-2]=val;
	}
	
	void chk(int&pos)
	{
		int a=p[pos-1],b=p[pos],c=p[pos+1];
		if(a>min(b,c)&&a<max(b,c))base(pos-1,pos+1),pos--;
		else base(pos+1,pos-1),pos++;
	}
	
	void mk(int m,int pos)
	{
		int val=p[pos];
//		cout<<"mk "<<m<<' '<<pos<<'\n';
		while(p[m]!=val)
		{
			chk(pos);
		}
	}
	
	int dfs(int pos)
	{
		if(pos<2)return 0;
		while(p[pos]<p[pos-1])
		{
			if(pos<3)return 0;
			if(p[pos-2]<p[pos])
			{
				base(pos,pos-2);
				return 1;
			}
			if(p[pos-2]<p[pos-1])
			{
				base(pos-2,pos);
				return 1;
			}
			if(!dfs(pos-1))return 0;
		}
		return 1;
	}
	
	void exsol(int m,int pmx)
	{
		if(pmx==0)
		{
			op[++tot]=(oper){m-2,m};
			op[++tot]=(oper){m-1,m+1};
			op[++tot]=(oper){m-1,m-3};
			op[++tot]=(oper){m+1,m-1};
		}
		else
		{
			op[++tot]=(oper){m-1,m+1};
			op[++tot]=(oper){m-3,m-1};
			op[++tot]=(oper){m+1,m-1};
			op[++tot]=(oper){m,m-2};
		}
		swap(p[m],p[m-1]);
		swap(p[m-2],p[m-3]);
	}
	
	void fix(int m,int pmx)
	{
		if(m<=1)return;
		int pos1,posn;
		for(int i=1;i<=m;i++)
		{
			if(p[i]==1)pos1=i;
			if(p[i]==m)posn=i;
		}
		if(pos1<posn)return mk(m,posn);
		mk(m,pos1);
		for(int i=1;i<m;i++)p[i]--;
		fix(m-1,0);
		for(int i=1;i<m;i++)p[i]++;
		if(p[m-1]!=m||!dfs(m-2))return;
		exsol(m,pmx);
	}
	
	void solve(int m,int pmx)
	{
		if(m<=1)return;
		int pos1,posn;
		for(int i=1;i<=m;i++)
		{
			if(p[i]==1)pos1=i;
			if(p[i]==m)posn=i;
		}
		if(pos1<posn)return mk(m,posn),solve(m-1,m);
		mk(m,pos1);int rtot=tot;
		for(int i=1;i<m;i++)q[i]=p[i];
		for(int i=1;i<m;i++)p[i]--;
		fix(m-1,0);
		for(int i=1;i<m;i++)p[i]++;
		if(p[m-1]!=m)
		{
			d[m]=1;tot=rtot;
			for(int i=1;i<m;i++)p[i]=m-q[i]+1;
			return solve(m-1,m);
		}
		rtot=tot;for(int i=1;i<m;i++)q[i]=p[i];
		if(pmx==-1||!dfs(m-2))
		{
			d[m]=1;tot=rtot;
			for(int i=1;i<m;i++)p[i]=m-q[i]+1;
			return solve(m-1,m);
		}
		exsol(m,pmx);solve(m-1,m);
	}
	
	void sol(int x)
	{
		for(int i=1;i<=n;i++)cin>>p[i];
		solve(n,-1);
	}
}A,B;

main()
{
	// freopen("in.txt","r",stdin);
//	freopen("hammer.in","r",stdin);
//	freopen("hammer.out","w",stdout);
	int t;
	cin>>n>>t;
	A.sol(1);
	B.sol(2);
	for(int i=1;i<=n;i++)
	{
		if(A.d[i]!=B.d[i]||A.p[i]!=B.p[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	if(t==1) return 0;
	cout<<A.tot+B.tot<<'\n';
	for(int i=1;i<=A.tot;i++)cout<<A.op[i].i<<' '<<A.op[i].j-A.op[i].i<<'\n';
//	puts("");
	for(int i=B.tot;i>=1;i--)cout<<B.op[i].j<<' '<<B.op[i].i-B.op[i].j<<'\n';
}
