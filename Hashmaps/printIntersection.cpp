#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> findIntersection(int *arr1, int *arr2, int n, int m)
{
    vector<int> output;
    unordered_map<int, int> intersection;

    for(int i = 0; i < n; i++)
    {
        intersection[arr1[i]]++;
    }

    for(int i = 0; i < m; i++)
    {
        if(intersection.count(arr2[i]) > 0)
        {
            output.push_back(arr2[i]);
            //intersection.erase(arr2[i]);          // Remove the element to avoid duplicates in the output
        }
    }
    return output;
}

int main()
{
    int arr1[] = {2, 6, 1, 2};
    int arr2[] = {1, 2, 3, 4, 2};

    vector<int> ans = findIntersection(arr1, arr2, 5, 5);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
