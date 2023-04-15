#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long unsigned int n;
    cin >> n;
    n=n+1;
    if (n < 3)
        cout << 0 << endl;
    long long unsigned int count = n / 2; // 筛掉一半偶数
    long long unsigned int notPrime[n];
    memset(notPrime, 0, sizeof(notPrime));
    for (long long unsigned int i = 3; i * i < n; i += 2)
    {
        if (!notPrime[i])
        {
            // 筛掉素数的奇数倍数
            for (long long unsigned int j = i * i; j < n; j += 2 * i)
            { // 从i*i开始筛
                if (!notPrime[j])
                {
                    notPrime[j] = true;
                    count--;
                }
            }
        }
    }
    cout<<count<<endl;
}
