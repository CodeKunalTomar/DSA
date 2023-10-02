#include <iostream>
using namespace std;

long staircase(int n)
{
    long *ans = new long[n + 1];

    ans[0] = 1, ans[1] = 1, ans[2] = 2, ans[3] = 4;

    for(int i = 4; i < n + 1; i++)
    {
        ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1];
    }

    return ans[n];
}

int main()
{
    int n;
    cin >> n;

    long ans = staircase(n);

    cout << ans;
}
