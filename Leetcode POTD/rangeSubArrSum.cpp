#include <bits/stdc++.h> // Includes all standard library headers

// Time Complexity (T.C.) = O(n2logn)
// Space Complexity = O(n2)


using namespace std;

// Function to calculate the sum of subarray sums within a specified range
int rangeSum(vector<int>& nums, int n, int left, int right) {
    const int MOD = 1000000007; // Large prime for modulo operation
    vector<int> subArrSum;

    // Generate all subarray sums
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += nums[j];
            subArrSum.push_back(current_sum);
        }
    }

    // Sort the subarray sums
    sort(subArrSum.begin(), subArrSum.end());

    // Calculate the sum of elements from 'left' to 'right' index (1-based index)
    long long ans = 0;
    for (int i = left - 1; i < right; i++) {
        ans = (ans + subArrSum[i]) % MOD;
    }

    return ans;
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    int left = 1;
    int right = 5;

    // Call the rangeSum function and display the result
    int result = rangeSum(nums, n, left, right);
    cout << "The sum of subarray sums from index " << left << " to " << right << " is: " << result << endl;

    return 0;
}
