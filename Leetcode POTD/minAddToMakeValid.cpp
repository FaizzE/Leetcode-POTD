#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(const string &s) {
    int paren = 0, size = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            size++;
        } else if (size > 0) {
            size--;
        } else {
            paren++;
        }
    }
    return paren + size;
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    int result = minAddToMakeValid(s);
    cout << "Minimum number of additions to make the parentheses valid: " << result << endl;

    return 0;
}
