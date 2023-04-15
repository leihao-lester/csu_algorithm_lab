#include <bits/stdc++.h>
using namespace std;

int n, a[100], b[100], l[100][100];
int main()
{
    int i, j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < b[0])
            l[i][0] = 1;
        else if (a[i] == b[0])
            l[i][0] = 0;
        else
            l[i][0] = -1;
    }
    for (i = n - 2; i >= 0; i--)
        for (j = 1; j < n - i; j++)
            if (a[i + j] < b[j])
                l[i][j] = l[i][j - 1] + 1;
            else if (a[i + j] > b[j])
                l[i][j] = l[i + 1][j - 1] - 1;
            else if (l[i + 1][j - 1] - 1 > l[i][j - 1])
                l[i][j] = l[i + 1][j - 1] - 1;
            else
                l[i][j] = l[i][j - 1];
    cout<<l[0][n - 1];
}