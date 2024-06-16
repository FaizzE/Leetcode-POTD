#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum number of patches required
int minPatches(vector<int>& nums, int n) {
    long maxReach = 0;
    int patch = 0;
    int i = 0;

    while (maxReach < n) {
        if (i < nums.size() && nums[i] <= maxReach + 1) {
            maxReach += nums[i];
            i++;
        } else {
            maxReach += (maxReach + 1);
            patch++;
        }
    }
    return patch;
}

int main() {
    // Test minPatches
    vector<int> nums = {1, 3};
    int n = 6;
    int result = minPatches(nums, n);
    cout << "Minimum number of patches required: " << result << endl;

    return 0;
}
