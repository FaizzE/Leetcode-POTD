class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size(); // Array ka size nikal lo.

        // Operation ko k times repeat karna hai.
        for(int i = 0; i < k; i++) {
            int min = 0; // Min variable smallest element ka index track karega.

            // Array ke har element ko check karo smallest element find karne ke liye.
            for(int j = 1; j < n; j++) {
                if(nums[j] < nums[min]) { // Agar nums[j] chhota hai nums[min] se, to min update karo.
                    min = j;
                }
            }

            // Smallest element ko mul se multiply kar do.
            nums[min] *= mul;
        }
        return nums; // Modified array return karo.
    }
};
