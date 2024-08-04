/*
LC - 1460.
Que. You are given two integer arrays of equal length target and arr. In one step, you can select
 any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.
Return true if you can make arr equal to target or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if two vectors can be made equal by permutation
bool canBeEqual(vector<int>& target, vector<int>& arr) {
    // Sort both vectors
    sort(arr.begin(), arr.end());
    sort(target.begin(), target.end());

    // Check if both vectors are equal after sorting
    for (int i = 0; i < target.size(); i++) {
        if (target[i] != arr[i]) {
            return false; // Return false if any elements differ
        }
    }
    return true; // Return true if all elements are equal
}

int main() {
    // Example input
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};

    // Call the canBeEqual function and display the result
    if (canBeEqual(target, arr)) {
        cout << "The arrays can be made equal by permutation." << endl;
    } else {
        cout << "The arrays cannot be made equal by permutation." << endl;
    }

    return 0;
}
