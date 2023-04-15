#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100
int tj[maxn], qw[maxn];
int pi[maxn];    //匹配存储
int hopex[maxn]; //田忌的期望值
int hopey[maxn]; //国王的期望值
int uesdx[maxn];
int uesdy[maxn];   //标记数组
int a[maxn][maxn]; //建图，存赚的钱
int n, minz, ans;
bool dfs(int k)
{
    uesdx[k] = 1;
    for (register int i = 1; i <= n; i++)
        if (!uesdy[i]) //未访问过
        {
            int t = hopex[k] + hopey[i] - a[k][i];
            if (!t)
            {
                uesdy[i] = 1;
                if (pi[i] == 0 || dfs(pi[i])) //此马未匹配或此马匹配的对象可以换人
                {
                    pi[i] = k;
                    return 1;
                }
            }
            else
                minz = min(minz, t); //找最小的代价
        }
    return 0;
}
void KM()
{
    for (register int i = 1; i <= n; i++)
        while (1)
        {
            minz = 0x7ffffff;
            memset(uesdx, 0, sizeof(uesdx));
            memset(uesdy, 0, sizeof(uesdy));
            if (dfs(i))
                break; //匹配失败，退出
            for (register int j = 1; j <= n; j++)
                if (uesdx[j])
                    hopex[j] -= minz; //田忌降期望值
            for (register int j = 1; j <= n; j++)
                if (uesdy[j])
                    hopey[j] += minz; //国王升期望值
        }
}
int main()
{
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++)
        scanf("%d", &tj[i]);
    for (register int i = 1; i <= n; i++)
        scanf("%d", &qw[i]);
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= n; j++)
        {
            if (tj[i] > qw[j])
                a[i][j] = 1;
            if (tj[i] == qw[j])
                a[i][j] = 0;
            if (tj[i] < qw[j])
                a[i][j] = -1;
        } //建边
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= n; j++)
            hopex[i] = max(hopex[i], a[i][j]); //设置初始期望值
    KM();                                      //跑ＫＭ
    for (register int i = 1; i <= n; i++)
        ans += a[pi[i]][i]; //记录答案
    cout << ans;            //输出
}