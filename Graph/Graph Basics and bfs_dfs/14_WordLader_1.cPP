#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == targetWord) return steps;

            for(int i = 0; i < word.size(); i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

class Solution1{
private:
    int ladder(vector<string>& wordList, string startword, string targetword) {
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startword, 0});
        s.erase(startword);
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == targetword) return steps;

            for(int i  = 0; i < word.size(); i++) {
                char orginal = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(s.find(word) != s.end()) {
                        q.push({word, steps+1});
                        s.erase(word);
                    }
                }
                word[i] = orginal;
            }
        }
        return 0;
    }
};

int main(int argc, char** argv) {

    return 0;
}