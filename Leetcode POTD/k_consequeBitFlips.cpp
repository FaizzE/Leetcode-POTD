#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCountFromPastForCurri = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k && nums[i - k] == 2) { // Was it flipped
                flipCountFromPastForCurri--;
            }

            if (flipCountFromPastForCurri % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipCountFromPastForCurri++;
                nums[i] = 2; // Marking as flipped
                flips++;
            }
        }

        return flips;
    }
};

int main() {
    // Test minKBitFlips
    Solution solution;
    vector<int> nums = {0, 1, 0};
    int k = 1;

    int result = solution.minKBitFlips(nums, k);
    cout << "Minimum number of K consecutive bit flips: " << result << endl;

    return 0;
}
