
#include <iostream>
#include <string>
using namespace std;

//recursion - Time Complexity will be 3 to the power n where n will be the maximum length of s and t
int editDistance(string s, string t)
{
    //base case
    if(s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    if(s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }

    else
    {
        //insert
        int x = editDistance(s.substr(1), t) + 1;

        //delete
        int y = editDistance(s, t.substr(1)) + 1;

        //update/replace
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(x, min(y, z));
    }
}

//memoization - Time and Space Complexity will be O(m * n)
int editDistance2_Helper(string s, string t, int **output)
{
    int m = s.length();
    int n = t.length();

     //base case
    if(s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    //check if ans already exists
    if(output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    if(s[0] == t[0])
    {
        ans = editDistance(s.substr(1), t.substr(1));
    }

    else
    {
        //insert
        int x = editDistance2_Helper(s.substr(1), t, output) + 1;

        //delete
        int y = editDistance2_Helper(s, t.substr(1), output) + 1;

        //update/replace
        int z = editDistance2_Helper(s.substr(1), t.substr(1), output) + 1;

        ans = min(x, min(y, z));

    }

    //save the ans for future use
    output[m][n] = ans;

    //return ans
    return ans;
}

int editDistance_2(string s, string t)
{
    int x = s.length();
    int y = s.length();

    int **output = new int*[x + 1];

    for(int i = 0; i <= x; i++)
    {
        output[i] = new int[y + 1];

        for(int j = 0; j <= y; j++)
        {
            output[i][j] = -1;
        }
    }

    return editDistance2_Helper(s, t, output);
}

//dynamic programming - Time and Space Complexity will be O(m * n)
int editDistance_3(string s, string t)
{
    int m = s.length();
    int n = t.length();

    int **output = new int*[m + 1];

    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    //fill 1st row
    for(int j = 0; j <=n; j++)
    {
        output[0][j] = j;
    }

    //fill 1st column
    for(int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }

            else
            {
                int x = output[i - 1][j];
                int y = output[i][j - 1];
                int z = output[i - 1][j - 1];

                output[i][j] = min(x, min(y, z)) + 1;
            }
        }
    }
    return output[m][n];
}


int main()
{
    string s, t;

    cin >> s >> t;

    cout << editDistance_2(s, t) << endl << editDistance(s, t) << endl << editDistance_3(s, t);
}
