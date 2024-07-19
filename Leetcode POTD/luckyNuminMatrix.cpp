#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns

        int rMinMax = INT_MIN;

        // Find the maximum value among the row minimums
        for (int row = 0; row < m; row++) {
            int rMin = INT_MAX;
            for (int col = 0; col < n; col++) {
                rMin = min(rMin, matrix[row][col]);
            }
            rMinMax = max(rMinMax, rMin);
        }

        int cMaxMin = INT_MAX;

        // Find the minimum value among the column maximums
        for (int col = 0; col < n; col++) {
            int cMax = INT_MIN;
            for (int row = 0; row < m; row++) {
                cMax = max(cMax, matrix[row][col]);
            }
            cMaxMin = min(cMaxMin, cMax);
        }

        // Check if the row maximum minimum is equal to the column minimum maximum
        if (rMinMax == cMaxMin) {
            return {rMinMax}; // or return {cMaxMin}
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    };

    vector<int> result = sol.luckyNumbers(matrix);

    if (!result.empty()) {
        cout << "Lucky Number: " << result[0] << endl;
    } else {
        cout << "No Lucky Number found." << endl;
    }

    return 0;
}
