class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowCounts(grid[0].size(), 0), colCounts(grid.size(), 0);
        int n = grid.size(), m = grid[0].size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c]) {
                    rowCounts[c]++;
                    colCounts[r]++;
                }
            }
        }
        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c]) {
                    ans += rowCounts[c] > 1 || colCounts[r] > 1;
                }
            }
        }
        return ans;
    }
};
