#include <iostream>
using namespace std;

//recursion
int getMaxMoney(int *arr, int n)
{
     if(n <= 0)
     {
         return 0;
     }

     int a = getMaxMoney(arr + 2, n - 2);
     int b = getMaxMoney(arr + 1, n - 1);

     return max(a + arr[0], b);
}

 //dynamic programming
 int getMaxMoney2_helper(int *arr, int n, int *dp)
 {
     dp[0] = arr[0];
     dp[1] = max(arr[0], arr[1]);

     for(int i = 2; i < n; i++)
     {
         dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
     }

     return dp[n - 1];
 }

 int getMaxMoney_2(int *arr, int n)
 {
     int dp[n];

     return getMaxMoney2_helper(arr, n, dp);
 }

 int main()
 {
     int arr[] = {5, 5, 10, 100, 10, 5};

     cout << getMaxMoney(arr, 6) << endl;
     cout << getMaxMoney_2(arr, 6) << endl;
 }
