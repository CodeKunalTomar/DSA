//Time complexity should be O(nlogk) and space complexity should be not more than O(k).

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kSmallestElements(int *input, int n, int k)
{
    priority_queue<int> pq;

    for(int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }


    for(int i = k; i < n; i++)
    {
        if(input[i] < pq.top())
        {
            pq.pop();
            pq.push(input[i]);
        }
    }

    vector<int> ans;

    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;


}

int main()
{
    int input[]= {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    vector<int> ans = kSmallestElements(input, 13, 4);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
