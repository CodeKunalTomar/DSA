#include <iostream>
using namespace std;

int numberOfWaysToMakeChange(int *arr, int n, int V)
{
    int *dp = new int[V + 1];

    for(int i = 0; i < V + 1; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;			//there is only one way to make change of coin with value 0 i.e. using no coin

    for(int i = 0; i < n; i++)
    {
        for(int j = arr[i]; j <= V; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }

    return dp[V];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    cout << numberOfWaysToMakeChange(arr, 6, 250);
}
