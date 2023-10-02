
#include <iostream>
#include <string>
using namespace std;

//recursion - Time Complexity will be exponential i.e (3 to the power n)
int lcs(string s, string t)
{
    //base case
    if(s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    //recursive calls
    if(s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }

    else{
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));

        return max(a, max(b, c));
    }
}

//memoization - Time and Space Complexity will be O(m * n)
int lcs2_helper(string s, string t, int **output)
{
    int m = s.length();
    int n = t.length();

    //base case
    if(s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    //check if ans already exists
    if(output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans = 0;

    //recursive calls
    if(s[0] == t[0])
    {
        ans = 1 + lcs2_helper(s.substr(1), t.substr(1), output);
    }

    else{
        int a = lcs2_helper(s.substr(1), t, output);
        int b = lcs2_helper(s, t.substr(1), output);
        int c = lcs2_helper(s.substr(1), t.substr(1), output);

        ans = max(a, max(b, c));
    }

    //save your calculation
    output[m][n] = ans;

    //return ans
    return ans;
}

int lcs_2(string s, string t)
{
    int m = s.length();
    int n = t.length();

    int **output = new int*[m + 1];

    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];

        for(int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return lcs2_helper(s, t, output);
}

//dynamic programming - Time and Space Complexity will be O(m * n)
int lcs_3(string s, string t)
{
    int m = s.length();
    int n = t.length();

    int **output = new int*[m + 1];

    for(int i = 0; i <=m; i++)
    {
        output[i] = new int[n + 1];
    }

    //fill 1st row
    for(int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }

    //fill 1st column
    for(int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            //check if 1st character matches
            if(s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }

            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];

                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s, t;

    cin >> s >> t;

    cout << lcs(s, t) << endl;
    cout << lcs_2(s, t) << endl;
    cout << lcs_3(s, t) << endl;
}
