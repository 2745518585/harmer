#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
template<typename S> inline char gc(S &st)
{
    return st.eof()?EOF:st.readChar();
}
template<typename T,typename S> inline void read(T &x,S &st)
{
    T u=1,t=0;char c=gc(st);
    while(c<'0'||c>'9') {if(c==EOF) return x=0,void(); if(c=='-') u=-1; c=gc(st);}
    while(c>='0'&&c<='9') t*=10,t+=c-'0',c=gc(st);
    x=u*t;return;
}
const int N=1001;
int n,a[N],b[N];
int main(int argc,char **argv)
{
    registerTestlibCmd(argc,argv);
    read(n,inf);
    for(int i=1;i<=n;++i) read(a[i],inf);
    for(int i=1;i<=n;++i) read(b[i],inf);
    string p1=ans.readToken(),p2=ouf.readToken();
    if(p1!=p2)
    {
        quitf(_wa,"Wrong Answer");
    }
    if(p1=="NO") quitf(_ok,"Accepted");
    if(ouf.eof()) quitp(20,"invaild operation");
    int m;
    read(m,ouf);
    for(int l=1;l<=m;++l)
    {
        int x,y,w=0;
        read(x,ouf),read(y,ouf);
        if(x<1||x>n||y<1||y>n)
        {
            quitp(20,"invaild operation");
        }
        if(x<y)
        {
            for(int i=x+1;i<=y;++i) w+=(a[x]<a[i]?1:-1);
            if(w!=0)
            {
                quitp(20,"invaild operation");
            }
            for(int i=x+1;i<=y;++i) swap(a[i-1],a[i]);
        }
        else
        {
            for(int i=x-1;i>=y;--i) w+=(a[x]<a[i]?1:-1);
            if(w!=0)
            {
                quitp(20,"invaild operation");
            }
            for(int i=x-1;i>=y;--i) swap(a[i+1],a[i]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=b[i])
        {
            quitp(20,"invaild operation");
        }
    }
    quitf(_ok,"Accepted");
    return 0;
}