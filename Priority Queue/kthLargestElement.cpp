#include <iostream>
#include <queue>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
    priority_queue<int> pq;

    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }

    return pq.top();
}

int main()
{
    int arr[] = {2, 6, 10, 11, 13, 4, 1, 20};

    cout << kthLargest(arr, 8, 4);
}