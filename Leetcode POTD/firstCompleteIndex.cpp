class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int totalRows = mat.size(), totalCols = mat[0].size();
        vector<int> rowsPainted(totalRows), colsPainted(totalCols);
        unordered_map<int, pair<int, int>> valueToPosition;
        for (int r = 0; r < totalRows; r++) {
            for (int c = 0; c < totalCols; c++) {
                int val = mat[r][c];
                valueToPosition[val] = {r, c};
            }
        }
        for (int idx = 0; idx < arr.size(); idx++) {
            int number = arr[idx];
            auto [r, c] = valueToPosition[number];
            rowsPainted[r]++;
            colsPainted[c]++;
            if (rowsPainted[r] == totalCols || colsPainted[c] == totalRows) {
                return idx;
            }
        }
        return -1;  
    }
};
