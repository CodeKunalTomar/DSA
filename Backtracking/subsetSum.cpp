#include <iostream>
#include <vector>
using namespace std;

// Function to find count of subsets with sum equal to K
void countSubsetsWithSum(vector<int>& nums, int target, int idx, int currentSum, int& count) {
    // Base case: If the current sum equals the target, increment the count
    if (currentSum == target) {
        count++;
        return;
    }

    // Base case: If the index exceeds the array size or the current sum exceeds the target, return
    if (idx >= nums.size() || currentSum > target)
        return;

    // Include the current element in the subset
    countSubsetsWithSum(nums, target, idx + 1, currentSum + nums[idx], count);

    // Exclude the current element from the subset
    countSubsetsWithSum(nums, target, idx + 1, currentSum, count);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum K: ";
    cin >> target;

    int count = 0;
    countSubsetsWithSum(nums, target, 0, 0, count);

    cout << "Count of subsets with sum equal to " << target << " is: " << count << endl;

    return 0;
}
