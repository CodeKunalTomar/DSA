#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueCharacter(string s)
{
    unordered_map<char, int> exists;
    int index = 0;
    string ans;

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(exists[s[i]] == 0)
        {
            ans += s[i];            //Character append to a string
            index++;
            exists[s[i]]++;
        }
    }

    //cout << index;
    ans[index] = '\0';
    return ans;
}

int main()
{
    string s;
    cin >> s;

    string ans = uniqueCharacter(s);
    cout << ans;
}
