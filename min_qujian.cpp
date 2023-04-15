#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int N,L,R;
struct Edge
{
    int l,r;
}edge[maxn];
int dp[maxn];

int main()
{
    while(~scanf("%d%d%d",&N,&L,&R))
    {
        for(int i=1;i<=N;i++)
        {
            cin>>edge[i].l>>edge[i].r;
        }
        for(int i=0;i<=R-L;i++)
            dp[i]=100005;
        dp[0]=0;
        for(int i=L;i<=R;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(edge[j].l<i&&i<=edge[j].r)
                {
                    if(edge[j].l<L)edge[j].l=L;
                    dp[i-L]=min(dp[i-L],dp[edge[i].l-L]+1);
                }
            }
        }
        if(dp[R-L]==100005)cout<<-1<<endl;
        else cout<<dp[R-L]<<endl;
    }
    
}