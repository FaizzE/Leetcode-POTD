#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int> st;
        int i = 0;
        int j = 0;
        int maxLength = 0;

        while (j < n) {
            st.insert(nums[j]);

            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                ++i;
            }

            maxLength = max(maxLength, j - i + 1);
            ++j;
        }

        return maxLength;
    }
};

int main() {
    // Test longestSubarray
    Solution solution;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;

    int result = solution.longestSubarray(nums, limit);
    cout << "Longest subarray length within limit " << limit << ": " << result << endl;

    return 0;
}
