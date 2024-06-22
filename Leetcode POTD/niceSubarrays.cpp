#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;
        int count = 0;
        int result = 0;
        int i = 0;
        int j = 0;

        while (j < n) {
            if (nums[j] % 2 != 0) { 
                oddCount++;
                count = 0;
            }

            while (oddCount == k) {
                count++;
                if (i < n && nums[i] % 2 == 1) { 
                    oddCount--;
                }
                i++;
            }

            result += count;
            j++;
        }

        return result;
    }
};

int main() {
    // Test numberOfSubarrays
    Solution solution;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = solution.numberOfSubarrays(nums, k);
    cout << "Number of subarrays with " << k << " odd numbers: " << result << endl;

    return 0;
}
