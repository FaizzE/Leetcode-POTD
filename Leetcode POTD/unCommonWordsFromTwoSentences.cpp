#include <bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> words;
    vector<string> ans;
    
    // Process the first sentence
    string word = "";
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != ' ') {
            word += s1[i];
        } else {
            words[word]++;
            word.clear();
        }
    }
    if (!word.empty()) {
        words[word]++;
    }

    // Process the second sentence
    string word1 = "";
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] != ' ') {
            word1 += s2[i];
        } else {
            words[word1]++;
            word1.clear();
        }
    }
    if (!word1.empty()) {
        words[word1]++;
    }

    // Collect words that appear only once
    for (auto it : words) {
        if (it.second == 1) {
            ans.push_back(it.first);
        }
    }

    return ans;
}

int main() {
    string s1 = "apple banana orange";
    string s2 = "banana apple grape";
    vector<string> result = uncommonFromSentences(s1, s2);

    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
