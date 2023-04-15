#include<bits/stdc++.h>
using namespace std;
int n,m,k;

int clearmushroom(vector<vector<int>> cell,int n,int m)
{
    int result=0;
    for (int x1 = 0; x1 < n - 2; x1++)
    {
        for (int y1 = 0; y1 < m - 2; y1++)
        {
            int firstclear=0;
            vector<vector<int>> firstcell = cell;
            for (int i1 = 0; i1 < 3; i1++)
            {
                for (int j1 = 0; j1 < 3; j1++)
                {
                    if (firstcell[x1+i1][y1+j1]>0)
                    {
                        firstclear++;
                        firstcell[x1 + i1][y1 + j1]--;
                    }
                }
            }
            int secondclear = 0;
            for (int x2 = 0; x2 < n - 2; x2++)
            {
                for (int y2 = 0; y2 < m - 2; y2++)
                {
                    int secondclear = 0;
                    for (int i2 = 0; i2 < 3; i2++)
                    {
                        for (int j2 = 0; j2 < 3; j2++)
                        {
                            if (firstcell[x2 + i2][y2 + j2]>0)
                            {
                                secondclear++;
                            }
                        }
                        if (firstclear + secondclear > result)
                            result = firstclear + secondclear;
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    cin>>n>>m>>k;
    cout << "你好";
    vector<vector<int>> cell(n+1,vector<int>(m+1,0));
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        cell[x][y]++;
    }
    cout<<clearmushroom(cell,n,m)<<endl;
}