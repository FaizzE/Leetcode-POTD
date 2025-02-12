#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the sum of digits of a number
    int digitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    // Optimized Approach using Hash Map (O(N) Time Complexity)
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxSum = -1;

        for (int num : nums) {
            int sum = digitSum(num);

            // If another number with the same digit sum exists, update maxSum
            if (mp.find(sum) != mp.end()) {
                maxSum = max(maxSum, num + mp[sum]);
            }

            // Store the largest number for each digit sum
            if (mp.find(sum) == mp.end() || num > mp[sum]) {
                mp[sum] = num;
            }
        }
        return maxSum;
    }
};

/*  
=========================================================
✅ **Optimized Approach (O(N) Time Complexity)**
- Uses an **unordered_map** to store the largest number for each digit sum.
- Eliminates the need for **nested loops**, reducing time complexity to **O(N)**.
=========================================================
*/

/*  
====================== Brute Force Approach ======================
- Time Complexity: **O(N²)**
- This approach checks **all pairs** to find the maximum sum for equal digit sums.
==================================================================
*/
class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (digitSum(nums[i]) == digitSum(nums[j])) {
                    maxSum = max(maxSum, nums[i] + nums[j]);
                }
            }
        }
        return maxSum;
    }
};
