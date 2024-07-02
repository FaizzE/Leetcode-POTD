#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

vector<int> intersectSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Sort nums2
    sort(nums2.begin(), nums2.end());

    int i = 0;
    int j = 0;
    vector<int> ans;

    // Traverse through both arrays to find common elements
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    // Example usage
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 2, 3, 4};

    vector<int> result = intersectSortedArrays(nums1, nums2);

    // Print the result
    cout << "Intersection of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
