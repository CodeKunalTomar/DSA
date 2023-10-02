#include <iostream>
#include <queue>
using namespace std;

void findMedian(int arr[], int n)
{
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            max.push(arr[i]);
        }

        else
        {
            if(arr[i] < max.top())
            {
                max.push(arr[i]);
            }

            else
            {
                min.push(arr[i]);
            }
        }

        if(int(max.size() - min.size()) > 1)
        {
            int x = max.top();
            max.pop();
            min.push(x);
        }

        if(int(min.size() - max.size()) > 1)
        {
            int x =  min.top();
            min.pop();
            max.push(x);
        }

        int c = max.size() + min.size();

        if(c%2 == 0)
        {
            cout << (max.top() + min.top()) / 2 << " ";
        }

        else
        {
            if(max.size() > min.size())
            {
                cout << max.top() << " ";
            }

            else
            {
                cout << min.top() << " ";
            }
        }
    }
}

int main()
{
    int arr[] = {6, 2, 1, 3, 7, 5};

    findMedian(arr, 6);
}
