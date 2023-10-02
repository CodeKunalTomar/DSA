#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int highestFrequency(int *arr, int n)
{
    unordered_map<int, int> max;

    for(int i = 0; i < n; i++)
    {
        max[arr[i]]++;
    }

    int key = 0;
    int value = 0;

    for(int i = 0; i < n; i++)
    {
        if(max[arr[i]] > value)
        {
            key = arr[i];
            value = max[arr[i]];
        }
    }
    return key;
}

int main()
{
    int arr[] = {1, 4, 5};

    cout << highestFrequency(arr, 3);
}
