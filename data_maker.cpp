#include<bits/stdc++.h>
#include"orita.hpp"
using namespace std;
using namespace orita;
int a[10001];
void move(int x,int y)
{
    if(x<y) for(int i=x+1;i<=y;++i) swap(a[i-1],a[i]);
    else for(int i=x-1;i>=y;--i) swap(a[i+1],a[i]);
}
int main(int argc,char **argv)
{
    register_rnd(argc,argv);
    int p=atoi(getenv("outputed_sum"));
    int n=[&](){
        if(p<10) return rnd(2,8);
        if(p<20) return rnd(9,11);
        if(p<30) return rnd(12,25);
        if(p<40) return rnd(26,50);
        return rnd(51,200);
    }();
    // int n=rnd(2,8);
    printf("%d\n",n);
    if(rnd(3))
    {
        auto b=rnd_range(n);
        for(int i=1;i<=n;++i) a[i]=b[i-1];
        for(int i=1;i<=n;++i) printf("%d ",a[i]);printf("\n");
        int s=0;
        while(s<n*n)
        {
            int x=rnd(1,n);
            if(rnd(2))
            {
                int p=x+1,w=(a[x]<a[p]?-1:1);
                while(p<n&&w) w+=(a[x]<a[++p]?-1:1);
                if(w==0) move(x,p),++s;
            }
            else
            {
                int p=x-1,w=(a[x]<a[p]?-1:1);
                while(p>1&&w) w+=(a[x]<a[--p]?-1:1);
                if(w==0) move(x,p),++s;
            }
        }
        for(int i=1;i<=n;++i) printf("%d ",a[i]);printf("\n");
    }
    else
    {
        auto a=rnd_range(n);
        for(auto i:a) printf("%d ",i);printf("\n");
        a=rnd_range(n);
        for(auto i:a) printf("%d ",i);printf("\n");
    }
    return 0;
}