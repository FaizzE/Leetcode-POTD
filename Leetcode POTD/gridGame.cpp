class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL), bottomRowSum = 0;
        long long minMaxSum = LLONG_MAX;
        for (int column = 0; column < grid[0].size(); ++column) {
            topRowSum -= grid[0][column];
            minMaxSum = min(minMaxSum, max(topRowSum, bottomRowSum));
            bottomRowSum += grid[1][column];
        }
        return minMaxSum;
    }
};
