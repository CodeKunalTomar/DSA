#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(vector<vector<int>> &dp, int *p, int s, int e)
{
    if(e - s == 1)
    {
        return 0;
    }

    if(dp[s][e])
    {
        return dp[s][e];
    }

    int ans = INT_MAX;

    for(int k = s + 1; k < e; k++)
    {
        int temp = f(dp, p, s, k) + f(dp, p, k, e) + p[s] * p[k] * p[e];
        ans = min(ans, temp);
    }

    dp[s][e] = ans;
    return dp[s][e];
}

int mcm(int *p, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int ans = f(dp, p, 0, n);

    return ans;
}

int main()
{
    int p[] = {10, 15, 20, 25};

    cout << mcm(p, 3) << endl;
}
