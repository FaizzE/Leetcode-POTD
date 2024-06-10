#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) {
    int n = heights.size();
    vector<int> clone(n);  // Initialize clone with the same size as heights

    for (int i = 0; i < n; i++) {
        clone[i] = heights[i];
    }
    sort(clone.begin(), clone.end());

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (clone[i] != heights[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    cout << "Number of students in wrong positions: " << heightChecker(heights) << endl;
    return 0;
}
