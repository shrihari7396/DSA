#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsequences
void generateSubsequences(string &s, int index, string current, vector<string> &result) {
    // Base case: when we have considered all characters
    if (index == s.size()) {
        result.push_back(current);
        return;
    }

    // Include the current character
    generateSubsequences(s, index + 1, current + s[index], result);

    // Exclude the current character
    generateSubsequences(s, index + 1, current, result);
}

int main() {
    string s = "abccdefghijklmnopqrst";
    vector<string> subsequences;

    generateSubsequences(s, 0, "", subsequences);

    // Print all subsequences
    cout << "All Subsequences:\n";
    for (const string &subseq : subsequences) {
        cout << "\"" << subseq << "\"\n";
    }
    cout<<subsequences.size()<<endl;

    return 0;
}
