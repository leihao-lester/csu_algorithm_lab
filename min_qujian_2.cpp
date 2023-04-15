#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int N,L,R;
struct Edge
{
    int l,r;
}edge[maxn];

bool cmp(const struct Edge a,const struct Edge b)
{
    if(a.l==b.l)return a.r<b.r;
    return a.l<b.l;
}
int main()
{
    while(~scanf("%d%d%d",&N,&L,&R))
    {
        for(int i=1;i<=N;i++)
            cin>>edge[i].l>>edge[i].r;
        if(L==R)
        {
            int flag=0;
            for(int i=1;i<=N;i++)
            {
                if(edge[i].l<=L&&edge[i].r>=R)
                {
                    flag=1;
                    break;
                }
                
            }
            if(flag)cout<<1<<endl;
            else cout<<-1<<endl;
            continue;//注意
        }
        sort(edge+1,edge+N+1,cmp);
        if(edge[1].l>L)
        {
            cout<<-1<<endl;
            continue;
        }
        int y=L,index=1,ans=0,x;
        while(y<R)
        {
            x=y;
            for(int i=index;i<=N;i++)
            {
                if(edge[i].l<=x&&edge[i].r>=x)
                {
                    y=max(y,edge[i].r);
                }
                else if(edge[i].l>x)
                {
                    index=i;
                    break;
                }
            }
            if(x==y) break;
            else ans++;
        }
        if(y>=R) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}