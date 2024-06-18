#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum profit assignment
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = difficulty.size();
    int m = worker.size();

    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back({difficulty[i], profit[i]});
    }

    // Sort the jobs by difficulty
    sort(begin(vec), end(vec));

    // Update the profit to the maximum profit for any difficulty level <= current difficulty level
    for (int i = 1; i < vec.size(); i++) {
        vec[i].second = max(vec[i].second, vec[i - 1].second);
    }

    int totalProfit = 0;
    for (int i = 0; i < m; i++) {
        int workerDiffLevel = worker[i];

        // Binary search to find the maximum profit job this worker can do
        int l = 0, r = vec.size() - 1;
        int maxProfit = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= workerDiffLevel) {
                maxProfit = max(maxProfit, vec[mid].second);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        totalProfit += maxProfit;
    }

    return totalProfit;
}

int main() {
    // Test maxProfitAssignment
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};

    int result = maxProfitAssignment(difficulty, profit, worker);
    cout << "Total maximum profit: " << result << endl;

    return 0;
}
