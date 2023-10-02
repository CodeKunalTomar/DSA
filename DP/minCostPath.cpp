
#include <iostream>
#include <cmath>
using namespace std;

//recursion - Time Complexity will be O(3 to the power m or n depending upon whether m is larger or n)
int minCostPathHelper(int **input, int m, int n, int i, int j)
{
    //base case
    if(i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if(i >= m || j >= n)
    {
        return INT_MAX;
    }

    //recursive calls
    int x = minCostPathHelper(input, m, n, i, j+1);
    int y = minCostPathHelper(input, m, n, i+1, j+1);
    int z = minCostPathHelper(input, m, n, i+1, j);

    //small calculation
    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}

//memoization - Space and Time Complexity will be O(m*n)
int minCostPathHelper_2(int **input, int m, int n, int i, int j, int **output)
{
    //base case
    if(i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if(i >= m || j >= n)
    {
        return INT_MAX;
    }

    //check if ans already exists
    if(output[i][j] != -1)
    {
        return output[i][j];
    }

    //recursive calls
    int x = minCostPathHelper_2(input, m, n, i, j+1, output);
    int y = minCostPathHelper_2(input, m, n, i+1, j+1, output);
    int z = minCostPathHelper_2(input, m, n, i+1, j, output);

    //small calculation
    int ans = min(x, min(y, z)) + input[i][j];

    //save the output for future use
    output[i][j] = ans;

    return ans;
}

int minCostPath_2(int **input, int m, int n)
{
    int **output = new int*[m];

    for(int i = 0; i < m; i++)
    {
        output[i] = new int[n];

        for(int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }

    return minCostPathHelper_2(input, m, n, 0, 0, output);
}

//dynamic programming - Time and Space Complexity will be O(m*n)
int minCostPath_3(int **input, int m, int n)
{
    int **output = new int*[m];

    for(int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    //fill the last cell i.e. destination
    output[m - 1][n - 1] = input[m - 1][n - 1];

    //fill last row (right to left)
    for(int j = n - 2; j>=0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    //fill last column (bottom to top)
    for(int i = m - 2; i>=0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    //fill remaining cells
    for(int i = m - 2; i>=0; i--)
    {
        for(int j = n - 2; j>=0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }

    return output[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;

    int **input = new int*[m];

    for(int i = 0; i < m; i++)
    {
        input[i] = new int[n];

        for(int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    cout << minCostPath(input, m, n) << endl;
    cout << minCostPath_2(input, m, n) << endl;
    cout << minCostPath_3(input, m, n) << endl;
}
