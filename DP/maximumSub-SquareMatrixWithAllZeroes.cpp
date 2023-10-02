
#include <iostream>
using namespace std;

int findMaxSquaresWithAllZeroes(int **arr, int row, int col)
{
    int **dp = new int*[row];

    for(int i = 0; i < row; i++)
    {
        dp[i] = new int[col];

        for(int j = 0; j < col; j++)
        {
            dp[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i = 0; i < row; i++)
    {
        if(arr[i][0] == 0)
        {
            dp[i][0] = 1;
        }

        else
        {
            dp[i][0] = 0;
        }

        ans = max(ans, dp[i][0]);
    }

    for(int j = 0; j < col; j++)
    {
        if(arr[0][j] == 0)
        {
            dp[0][j] = 1;
        }

        else
        {
            dp[0][j] = 1;
        }

        ans = max(ans, dp[0][j]);
    }

    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if(arr[i][j] == 1)
            {
                dp[i][j] = 0;
            }

            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    int row, col;
    cin >> row >> col;
    int **arr = new int*[row];

    for(int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for(int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquaresWithAllZeroes(arr, row, col);
}
