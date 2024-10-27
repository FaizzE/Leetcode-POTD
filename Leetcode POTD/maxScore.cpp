#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

public:
    long long maxScore(vector<int>& arr) {
        int n = arr.size();
        long long normalGCD = arr[0], normalLCM = arr[0];

        for (int val : arr) {
            normalGCD = gcd(normalGCD, val);
            normalLCM = lcm(normalLCM, val);
        }

        long long bestScore = normalGCD * normalLCM;

        for (int skipIdx = 0; skipIdx < n; skipIdx++) {
            long long currGCD = 0, currLCM = 1;
            for (int j = 0; j < n; j++) {
                if (j != skipIdx) {
                    currGCD = gcd(currGCD, arr[j]);
                    currLCM = lcm(currLCM, arr[j]);
                }
            }
            bestScore = max(bestScore, currGCD * currLCM);
        }

        return bestScore;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long score = solution.maxScore(arr);
    cout << "Maximum Score: " << score << endl;

    return 0;
}
