#include <iostream>
#include <string>

// Note : Very Simple If String Have a Vowel Then Return true otherwise return false

using namespace std;

// Function to check if Alice wins
bool doesAliceWin(string s) {
    // Check each character in the string
    for (int i = 0; i < s.size(); i++) {
        // If the character is a vowel, return true
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            return true;
        }
    }
    // If no vowels are found, return false
    return false;
}

int main() {
    // Test cases
    string test1 = "hello";
    string test2 = "sky";
    string test3 = "bcdfg";

    // Print the results of the test cases
    cout << "Does Alice win for \"" << test1 << "\"? " << (doesAliceWin(test1) ? "Yes" : "No") << endl;
    cout << "Does Alice win for \"" << test2 << "\"? " << (doesAliceWin(test2) ? "Yes" : "No") << endl;
    cout << "Does Alice win for \"" << test3 << "\"? " << (doesAliceWin(test3) ? "Yes" : "No") << endl;

    return 0;
}
