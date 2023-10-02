#include <iostream>
using namespace std;
#include <stack>

bool checkRedundantBrackets(string expression)
{
    stack<char> s;

    int i = 0, j = 0, count = 0;

    while(expression[i] != '/0')
    {
        while(expression[i] != ')')
        {
            if(expression[i] == '\0')
            {
                return false;
            }
            s.push(expression[i]);
            i++;
        }

        if(expression[i] == ')')
        {
            while(s.top() != '(')
            {
                s.pop();
                count++;
            }

            if(count == 0 || count == 1)
            {
                return true;
            }

            else
            {
                s.pop();
                count = 0;
            }
        }
        i++;
    }
    return false;
}

int main()
{
    string expression;
    cin >> expression;

    bool ans = checkRedundantBrackets(expression);

    cout << (ans == 1 ? "True" : "False");
}