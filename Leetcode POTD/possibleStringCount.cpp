#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1; // Start with one because the first character counts
        for (int i = 0; i < word.size() - 1; i++) { // Loop until the second last character
            if (word[i] == word[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    string word;

    cout << "Enter a string: ";
    cin >> word; // Input the string from the user

    int count = solution.possibleStringCount(word);
    cout << "Possible string count: " << count << endl;

    return 0;
}
