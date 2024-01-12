#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1001;
int n;
struct harmer
{
    int a[N];
    vector<pair<int,int>> ans;
    void move(int x,int y)
    {
        if(x<y) for(int i=x+1;i<=y;++i) swap(a[i-1],a[i]);
        else for(int i=x-1;i>=y;--i) swap(a[i+1],a[i]);
        ans.push_back(make_pair(x,y));
    }
    bool check(int n)
    {
        int x=1,y=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]<a[x]) x=i;
            if(a[i]>a[y]) y=i;
        }
        return x<y;
    }
    int find(int n)
    {
        int x=1,y=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]<a[x]) x=i;
            if(a[i]>a[y]) y=i;
        }
        return max(x,y);
    }
    void order(int n)
    {
        if(a[n-1]<a[n]) return;
        order(n-1);
        if(a[n-2]<a[n]&&a[n]<a[n-1]) move(n,n-2);
        if(a[n]<a[n-2]&&a[n-2]<a[n-1]) move(n-2,n);
    }
    void take(int n)
    {
        int x=find(n);
        if(x==n) return;
        if((a[x-1]<a[x])^(a[x-1]<a[x+1])) move(x-1,x+1);
        else move(x+1,x-1);
        take(n);
    }
    void fix(int n)
    {
        if(n==1) return;
        int w=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(a[j]<a[i]) ++w;
            }
        }
        if(w>(n-1)*(n-2)/2) return;
        take(n);
        if(check(n-1)==false) fix(n-1);
        take(n-1);
        order(n-2);
        if(a[n-3]<a[n-2])
        {
            if(a[n+1]>a[n-1])
            {
                move(n-1,n+1);
                move(n-3,n-1);
                move(n+1,n-1);
                move(n,n-2);
            }
            else if(a[n+1]<a[n])
            {
                move(n-2,n);
                move(n-1,n+1);
                move(n-1,n-3);
                move(n+1,n-1);
            }
        }
    }
    void solve(int n)
    {
        if(n==1) return;
        bool u=false;
        if(check(n)==false)
        {
            for(int i=1;i<=n;++i) a[i]=n-a[i]+1;
            u=true;
        }
        take(n);
        if(check(n-1)==false) fix(n-1);
        solve(n-1);
        if(u)
        {
            for(int i=1;i<=n;++i) a[i]=n-a[i]+1;
        }
    }
}a1,a2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a1.a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a2.a[i]);
    }
    a1.solve(n);
    a2.solve(n);
    if([&]()
    {
        for(int i=1;i<=n;++i) if(a1.a[i]!=a2.a[i]) return true;
        return false;
    }())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("%d\n",a1.ans.size()+a2.ans.size());
    for(auto i:a1.ans)
    {
        printf("%d %d\n",i.first,i.second);
    }
    reverse(a2.ans.begin(),a2.ans.end());
    for(auto i:a2.ans)
    {
        printf("%d %d\n",i.second,i.first);
    }
    return 0;
}