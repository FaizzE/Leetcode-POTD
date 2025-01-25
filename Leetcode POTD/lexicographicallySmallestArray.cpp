class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> nums_copy(nums);
        sort(nums_copy.begin(), nums_copy.end());
        int grp = 0;
        unordered_map<int, int> num_grp;
        num_grp[nums_copy[0]] = grp;
        unordered_map<int, list<int>> grp_lst;
        grp_lst[grp] = {nums_copy[0]};
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums_copy[i] - nums_copy[i - 1]) > limit) grp++;
            num_grp[nums_copy[i]] = grp;
            if (!grp_lst.count(grp)) grp_lst[grp] = {};
            grp_lst[grp].push_back(nums_copy[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i], grp_id = num_grp[val];
            nums[i] = grp_lst[grp_id].front();
            grp_lst[grp_id].pop_front();
        }
        return nums;
    }
};
