#include <iostream>
#include <cmath>
using namespace std;

int allWays_helper(int x, int n, int currNo, int *dp)
{
    if(x < 0)
    {
        return 0;
    }

    if(x == 0)
    {
        return 1;
    }

    int ans = 0;

    for(int i = currNo; pow(i, n) <= x; i++)
    {
        ans += allWays_helper(x - pow(i, n), n, i + 1, dp);
    }

    dp[x] = ans;
    return dp[x];
}

int allWays(int x, int n)
{
    int dp[100000];

    for(int i = 0; i < 100000; i++)
    {
        dp[i] = -1;
    }

    allWays_helper(x, n, 1, dp);
}

int main()
{
    cout << allWays(100, 2);
}
