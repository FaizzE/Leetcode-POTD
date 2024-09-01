#include<bits/stdc++.h>
using namespace std;

// 1st Approach
vector<vector<int>> construct2DArraySingleLoop(vector<int>& original, int m, int n) {
    vector<vector<int>> ans(m, vector<int>(n));
    
    if (original.size() != m * n) return {};
    
    for (int i = 0; i < original.size(); i++) {
        int row = i / n;
        int col = i % n;
        ans[row][col] = original[i];
    }
    return ans;
}

// 2nd Approach
vector<vector<int>> construct2DArrayNestedLoop(vector<int>& original, int m, int n) {
    vector<vector<int>> ans(m, vector<int>(n));
    
    if (original.size() != m * n) return {};

    int idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = original[idx];
            idx++;
        }
    }
    return ans;
}

int main() {
    vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Example input
    int m = 3, n = 3;

    cout << "Choose the approach: 1 (Single Loop) or 2 (Nested Loop): ";
    int choice;
    cin >> choice;

    vector<vector<int>> result;

    if (choice == 1) {
        result = construct2DArraySingleLoop(original, m, n);
    } else if (choice == 2) {
        result = construct2DArrayNestedLoop(original, m, n);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    if (result.empty()) {
        cout << "Conversion not possible with given dimensions." << endl;
    } else {
        cout << "Resulting 2D Array:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
