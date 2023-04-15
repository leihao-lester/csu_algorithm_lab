using namespace std;
#include<bits/stdc++.h>
#define maxn 1000
int n,c;
int v[maxn],w[maxn];
int maxx=0;
int a[maxn][maxn];
clock_t start,ending;

int main()
{
    cout<<"请输入物品个数：";
    cin>>n;
    cout<<"请输入背包大小：";
    cin>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    start=clock();
    for(int i=0;i<c;i++)
    {
        a[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        a[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(w[i]>j)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
        }
    }
    maxx=a[n][c];
    ending=clock();
    cout<<"本次程序耗时为："<<(double)(ending-start)*CLOCKS_PER_SEC<<endl;
    cout<<"最大价值为："<<maxx<<endl;
}

//0-1背包问题测试样例
// 25 
// 300
// 95 89
// 75 59
// 23 19
// 73 43 
// 50 100
// 22 72
// 6 44
// 57 16
// 89 7
// 98 64
// 20 50
// 46 25
// 83 105
// 55 33
// 11 20
// 77 92
// 22 22
// 29 87
// 50 46
// 99 90
// 79 83
// 58 14
// 86 54
// 11 79
// 28 72