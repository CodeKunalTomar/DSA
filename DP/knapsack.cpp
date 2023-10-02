#include <iostream>
using namespace std;

//recursion
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    //base case
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if(weight[0] > maxWeight)
    {
        return knapsack(weight + 1, value + 1, n - 1, maxWeight);
    }

    //recursive calls
    int x = knapsack(weight + 1, value + 1, n - 1, maxWeight - weight[0]) + value[0];
    int y = knapsack(weight + 1, value + 1, n - 1, maxWeight);

    return max(x, y);
}

//memoization
int knapsack2_helper(int * weight, int *value, int n, int maxWeight, int **output)
{
    //base case
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if(output[maxWeight][n] != -1)
    {
        return output[maxWeight][n];
    }

    if(weight[0] > maxWeight)
    {
        output[maxWeight][n] = knapsack(weight + 1, value + 1, n - 1, maxWeight);
        return output[maxWeight][n];
    }

    //recursive calls
    int x = knapsack(weight + 1, value + 1, n - 1, maxWeight - weight[0]) + value[0];
    int y = knapsack(weight + 1, value + 1, n - 1, maxWeight);

    output[maxWeight][n] = max(x, y);
    return output[maxWeight][n];
}

int knapsack_2(int *weight, int *value, int n, int maxWeight)
{
    int m = 102;
    int k = 22;

    int **output = new int*[m + 1];

    for(int i = 0; i < m; i++)
    {
        output[i] = new int[k + 1];

        for(int j = 0; j < k; j++)
        {
            output[i][j] = -1;
        }
    }

    knapsack2_helper(weight, value, n, maxWeight, output);
}

//dynamic programming
int knapsack_3(int *weight, int *value, int n, int maxWeight)
{
    int dp[n + 1][maxWeight + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxWeight; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else
            {
                if(weight[i - 1] > maxWeight)
                {
                    dp[i][j] = dp[i - 1][j];
                }

                else
                {
                    dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i -1][j]);
                }
            }
        }
    }
    return dp[n][maxWeight];
}

int main()
{
    int weights[] = {1, 2, 4, 5};
    int values[] = {5, 4, 8, 6};
    int W = 5;

    cout << knapsack(weights, values, 4, W) << endl;
    cout << knapsack_2(weights, values, 4, W) << endl;
    cout << knapsack_3(weights, values, 4, W) << endl;
}

