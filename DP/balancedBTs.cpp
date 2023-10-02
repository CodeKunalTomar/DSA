
#define mod 1000000007
#include <iostream>
#include <cmath>
using namespace std;

//recursion
int balancedBTs(int h)
{
    if(h <= 1)
    {
        return 1;
    }

    //int mod = (int) (pow(10, 9)) + 7;           //with the help of mod we limit the ans in the range of integer
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int temp1 = (int) (((long)(x)*x) % mod);
    int temp2 = (int) ((2 * (long)(x) * y) % mod);

    int ans = (temp1 + temp2) % mod;
    return ans;
}

//memoization
int balancedBTs_helper(int h, int *arr)
{
    if(h <= 1)
    {
        return 0;
    }

    if(arr[h] != 0)
    {
        return arr[h];
    }

    //we can use below step also
    //int mod = (int) (pow(10, 9)) + 7;           //with the help of mod we limit the ans in the range of integer
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int temp1 = (int) (((long)(x)*x) % mod);
    int temp2 = (int) ((2 * (long)(x) * y) % mod);

    arr[h] = (temp1 + temp2) % mod;
    return arr[h];

}

int balancedBTs_2(int h)
{
    int *arr = new int[h + 1];

    for(int i = 0; i < h + 1; i++)
    {
        arr[i] = 0;
    }

    balancedBTs_helper(h, arr);
}

//dynamic programming
int balancedBTs_3(int h)
{
    int *arr = new int[h + 1];

    arr[0] = 1;
    arr[1] = 1;

    for(int i = 2; i < h + 1; i++)
    {
        int temp1 = (int) (((long)(arr[i - 1])*arr[i - 1]) % mod);
        int temp2 = (int) ((2 * (long)(arr[i - 1]) * arr[i - 2]) % mod);

        arr[i] = (temp1 + temp2) % mod;
    }

    return arr[h];
}

int main()
{
    int h;
    cin >> h;

    cout << balancedBTs_3(h);
}
