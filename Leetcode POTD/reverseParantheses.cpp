#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string reverseParentheses(string s) {
    stack<string> st;
    string current;

    for (char c : s) {
        if (c == '(') {
            st.push(current);
            current.clear();
        } else if (c == ')') {
            reverse(current.begin(), current.end());
            if (!st.empty()) {
                current = st.top() + current;
                st.pop();
            }
        } else {
            current += c;
        }
    }

    return current;
}

int main() {
    string s = "(u(love)i)";
    cout << reverseParentheses(s) << endl;  // Output should be "iloveu"
    return 0;
}
