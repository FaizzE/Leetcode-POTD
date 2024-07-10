#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int minOperations(vector<string>& logs) {
    // Approach 1
    int depth = 0;

    for(string &log : logs) {
        if(log == "../") {
            depth = max(0, depth - 1);
        }
        else if(log == "./") {
            continue;
        }
        else {
            depth++;
        }
    }
    return depth;
}

int minOperationsStack(vector<string>& logs) {
    // Approach 2
    stack<string> st;

    for (const string& currentOperation : logs) {
        if (currentOperation == "../") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (currentOperation != "./") {
            st.push(currentOperation);
        }
    }

    return st.size();
}

int main() {
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    
    // Using approach 1
    int depth = minOperations(logs);
    cout << "Depth (Approach 1): " << depth << endl;
    
    // Using approach 2
    int size = minOperationsStack(logs);
    cout << "Size of stack (Approach 2): " << size << endl;

    return 0;
}
