#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        ll totalSum = accumulate(nums.begin(),nums.end(),0LL);

        ll leftSum = 0;
        ll rightSum = 0;
        int splits = 0;

        for(int i=0; i<n-1; i++) {
            leftSum += nums[i];
            rightSum = totalSum - leftSum;
            if(leftSum >= rightSum) splits++;
        }
        return splits;
    }
};
