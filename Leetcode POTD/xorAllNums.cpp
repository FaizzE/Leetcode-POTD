class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1 = 0, x2 = 0;
        int l1 = nums1.size(), l2 = nums2.size();
        if (l2 % 2 != 0) {
            for (int n : nums1) x1 ^= n;
        }
        if (l1 % 2 != 0) {
            for (int n : nums2) x2 ^= n;
        }
        return x1 ^ x2;
    }
};
