#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
    int *dp = new int[n + 1];

    dp[0] = false;
    dp[1] = true;

    for(int i = 2; i <= n; i++)
    {
	//if any player loses i - 1 or i - x or i - y game then he will definitely win the game
        if(i - 1 >= 0 && !dp[i - 1])
        {
            dp[i] = true;
        }

        else if(i - x >= 0 && !dp[i - x])
        {
            dp[i] = true;
        }

        else if(i - y >= 0 && !dp[i - y])
        {
            dp[i] = true;
        }

        else
        {
            dp[i] = false;
        }
    }

    if(dp[n])
    {
        return "Beerus";
    }

    else
    {
        return "Whis";
    }
}

int main()
{
    int n, x, y;

    cin >> n >> x >> y;

    string ans = findWinner(n, x, y);

    cout << ans << endl;
}
