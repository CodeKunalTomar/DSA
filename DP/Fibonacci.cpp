#include <iostream>
using namespace std;

//Time Complexity of this approach using recursion(brute force) is O[2 power n]
int fibo(int n)
{
    if(n <= 1)
    {
        return n;
    }

    int a = fibo(n - 1);
    int b = fibo(n - 2);

    return a + b;
}

//Time Complexity of this approach using memoization which is a top-down process is O[n]
int fibo_helper(int n, int *ans)
{
    if(n <= 1)
    {
        return n;
    }

   //check if output already exists
   if(ans[n] != -1)
   {
       return ans[n];
   }

   int a = fibo_helper(n - 1, ans);
   int b = fibo_helper(n - 2, ans);

   //save the output for future use
   ans[n] = a + b;

   //return the final output
   return ans[n];
}

int fibo_2(int n)
{
    int *ans = new int[n + 1];

    for(int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return fibo_helper(n, ans);
}

//Approach using iteration(Dynamic Programming) which is a bottom-up process
int fibo_3(int n)
{
    int *ans =  new int[n + 1];

    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i < n + 1; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

int main()
{
    int n = 5;

    int ans = fibo_3(n);
    cout << ans;
}
