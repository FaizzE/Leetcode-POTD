#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to find the maximized capital
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();

    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++) {
        vec[i] = {capital[i], profits[i]};
    }

    sort(vec.begin(), vec.end());

    int i = 0;

    priority_queue<int> pq;

    while (k--) {
        while (i < n && vec[i].first <= w) {
            pq.push(vec[i].second);
            i++;
        }
        if (pq.empty())
            break;
        w += pq.top();
        pq.pop();
    }
    return w;
}

int main() {
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    int result = findMaximizedCapital(k, w, profits, capital);
    cout << "Maximized capital: " << result << endl;

    return 0;
}
