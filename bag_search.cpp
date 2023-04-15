using namespace std;
#include<bits/stdc++.h>
#define maxn 1000000
int n,c;
int v[maxn],w[maxn];
int maxx=0;
int a[maxn];
clock_t start,ending;
void checkmax()
{
    int weight=0,value=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            weight+=w[i];
            value+=v[i];
        }
    }
    if(weight<=c && value>maxx)
    {
        maxx=value;
    }
}

void search(int x)
{
    if(x>n)
    {
        checkmax();
    }
    else
    {
        a[x]=0;
        search(x+1);
        a[x]=1;
        search(x+1);
    }
}

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
    // search(1);

    ending=clock();
    cout<<"本次程序耗时为："<<(double)(ending-start)*CLOCKS_PER_SEC<<endl;
    cout<<"最大价值为："<<maxx<<endl;
}
/*
0-1背包问题测试样例
25 
300
95 89
75 59
23 19
73 43 
50 100
22 72
6 44
57 16
89 7
98 64
20 50
46 25
83 105
55 33
11 20
77 92
22 22
29 87
50 46
99 90
79 83
58 14
86 54
11 79
28 72
*/