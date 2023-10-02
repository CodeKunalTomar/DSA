#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayWithZeroSum(int arr[], int n)
{
    unordered_map<int, int> sumMap;
    int maxLength = 0;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum == 0)
        {
            maxLength = i + 1;
        }

        if(sumMap.find(sum) != sumMap.end())
        {
            maxLength = max(maxLength, i - sumMap[sum]);
        }

        else
        {
            sumMap[sum] = i;
        }
    }
    return maxLength;
}

int main()
{
    int arr[] = {95, -97, -387, -435, -5, -70, 897, 127, 23, 284};

    int ans = longestSubarrayWithZeroSum(arr, 10);

    cout << ans;
}
