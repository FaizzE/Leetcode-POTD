#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, ans = 0;
        int maxE = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxE) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 3, 2, 3, 3, 3};
    cout << "Length of the longest subarray with the maximum element: " << solution.longestSubarray(nums) << endl;
    return 0;
}
