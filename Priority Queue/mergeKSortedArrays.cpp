#include <iostream>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& input)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i].size(); j++)
        {
            pq.push(input[i][j]);
        }
    }

    vector<int> ans;

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> v;

    cout << "Total no. of arrays: ";
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        int x;

        cout << i + 1 << "th array size: ";
        cin >> x;

        for(int j = 0; j < x; j++)
        {
            cout << "Enter element " << j + 1 << " of array " << i + 1 << ": ";
            int y;
            cin >> y;
            temp.push_back(y);
        }
        v.push_back(temp);
    }

    vector<int> ans = mergeKSortedArrays(v);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
}
