#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,a[N],b[N];
int main(int argc,char **argv)
{
    ifstream infile(argv[1]),outfile(argv[2]),ansfile(argv[3]);
    infile>>n;
    for(int i=1;i<=n;++i) infile>>a[i];
    for(int i=1;i<=n;++i) infile>>b[i];
    string p1,p2;
    outfile>>p1;
    ansfile>>p2;
    if(p1!=p2)
    {
        printf("Wrong Answer");
        return 1;
    }
    if(p2=="NO") return 0;
    int m;
    ansfile>>m;
    for(int l=1;l<=m;++l)
    {
        int x,y,w=0;
        ansfile>>x>>y;
        if(x<1||x>n||y<1||y>n)
        {
            printf("invaild operation");
            return 1;
        }
        if(x<y)
        {
            for(int i=x+1;i<=y;++i) w+=(a[x]<a[i]?1:-1);
            if(w!=0)
            {
                printf("invaild operation");
                return 1;
            }
            for(int i=x+1;i<=y;++i) swap(a[i-1],a[i]);
        }
        else
        {
            for(int i=x-1;i>=y;--i) w+=(a[x]<a[i]?1:-1);
            if(w!=0)
            {
                printf("invaild operation");
                return 1;
            }
            for(int i=x-1;i>=y;--i) swap(a[i+1],a[i]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=b[i])
        {
            printf("Wrong Answer");
            return 1;
        }
    }
    return 0;
}