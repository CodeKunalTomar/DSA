#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    priority_queue<int> pq;

    for(int child = 1; child < n; child++)
    {
        int parent = child - 1 / 2;

        if(arr[parent] < arr[child])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {42, 20, 18, 6, 14, 11, 9, 4};

    cout << isMaxHeap(arr, 8);
}
