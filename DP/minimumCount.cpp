
#include <iostream>
#include <cmath>
using namespace std;

//recursion
int minCount(int n)
{
    if(sqrt(n) - floor(sqrt(n)) == 0)
    {
        return 1;
    }

    if(n <= 3)
    {
        return n;
    }

    int ans = n;

    for(int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + minCount(n - i*i));
    }

    return ans;
}

//memoization

int minCount_helper(int n, int *arr)
{
    if(sqrt(n) - floor(sqrt(n)) == 0)
    {
        arr[n] = 1;
        return arr[n];
    }

    if(n <= 3)
    {
        arr[n] = n;
        return arr[n];
    }

    int ans = n;

    if(arr[n] != 0)
    {
        return arr[n];
    }

    for(int i = 1; i*i <= n; i++)
    {
        ans = min(ans, 1 + minCount_helper(n - i*i, arr));
    }

    arr[n] = ans;

    return arr[n];
}

int minCount_2(int n)
{
    int *arr = new int[n + 1];

    for(int i = 0; i < n + 1; i++)
    {
        arr[i] = 0;
    }

    return minCount_helper(n, arr);
}

//dynamic programming
int minCount_3(int n)
{
    if(sqrt(n) - floor(sqrt(n)) == 0)
    {
        return 1;
    }

    int *ans = new int[n + 1];

    if(n <= 3)
    {
        ans[n] = n;
    }

    for(int i = 4; i < n + 1; i++)
    {
        ans[i] = i;

        for(int x = 1; x * x <= n; x++)
        {
           ans[i] = min(ans[i], 1 + minCount_3(n - x*x));
        }
    }

    return ans[n];
}

int main()
{
    int n = 12;

    cout << minCount_3(n);
}
