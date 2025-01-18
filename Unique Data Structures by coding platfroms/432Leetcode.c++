#include <bits/stdc++.h>
using namespace std;

class AllOne {
    unordered_map<string, int> m;
    map<int, set<string>> freq;

public:
    AllOne() {}

    void inc(string key) {
        int count = m[key];
        if (count > 0) {
            freq[count].erase(key);
            if (freq[count].empty()) {
                freq.erase(count);
            }
        }
        m[key]++;
        freq[m[key]].insert(key);
    }

    void dec(string key) {
        if (m.find(key) == m.end()) {
            return;
        }
        int count = m[key];
        freq[count].erase(key);
        if (freq[count].empty()) {
            freq.erase(count); 
        }
        m[key]--;
        if (m[key] == 0) {
            m.erase(key);
        } else {
            freq[m[key]].insert(key);
        }
    }

    string getMaxKey() {
        if (freq.empty())
            return "";
        auto it = freq.rbegin();
        return *(it->second.begin());
    }

    string getMinKey() {
        if (freq.empty())
            return "";
        auto it = freq.begin();
        return *(it->second.begin());
    }
};
