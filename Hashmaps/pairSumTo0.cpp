
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int countPairsSumTo0(int *arr, int n)
{
    unordered_map<int, int> hashmap;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        hashmap[arr[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        int target = - arr[i];

        if(hashmap.count(target) > 0)
        {
            count += hashmap[arr[i]];
        }

        if(arr[i] == target)
        {
            count--;
        }
    }
    count /= 2;

    return count;
}

int main()
{
    int arr[] = {2, -2, -2};

    cout << countPairsSumTo0(arr, 3);
}


