#include<bits/stdc++.h>
using namespace std;


int longestSquareStreak(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int maxStk = 0;
    for (auto& val : nums) {
        int stk = 0;
        long long cur = val;

        while (st.find(cur) != st.end()) {
            stk++;

            if (cur * cur > 1e5) {
                break;
            }
            cur = cur * cur;
        }
        maxStk = max(maxStk, stk);
    }
    if (maxStk < 2) return -1;

    return maxStk;
}

int main() {
    vector<int> nums = {2, 4, 16, 256, 65536}; // Example input
    int result = longestSquareStreak(nums);
    cout << "The longest square streak is: " << result << endl;
    return 0;
}
