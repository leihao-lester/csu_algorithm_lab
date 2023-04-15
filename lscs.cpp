#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
#define N 2100
#define met(a, b) memset(a, b, sizeof(a))
#define INF 0x3f3f3f3f

int n, vis[N], used[N], G[N][N];
struct node
{
    int att, life;
}a[N], b[N];

bool Find(int u)
{
    for(int i=1; i<=n; i++)
    {
        if(!vis[i] && G[u][i])
        {
            vis[i] = 1;
            if(!used[i] || Find(used[i]))
            {
                used[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        met(G, 0);
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            cin>>a[i].life>>a[i].att;
        for(int i=1; i<=n; i++)
            cin>>b[i].life>>b[i].att;
        for(int i=1; i<=n; i++)//学长;
        {
            for(int j=1; j<=n; j++)//对手;
            {
                int Life1 = a[i].life - b[j].att;//对手打学长；
                int Life2 = b[j].life - a[i].att;//学长打对手；
                if(Life1 > 0 && Life2 <= 0)
                    G[i][j] = 1;
            }
        }
        met(used, 0);
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            met(vis, 0);
            if(Find(i))
                ans++;
        }
        if(ans == n)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}