#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int index(char ch) {
        return (ch - 'a');
    }

    pair<int, int> getEdge(string s1, string s2) {
        int i = 0, j = 0, m = s1.size(), n = s2.size();
        while (i < m && j < n && s1[i] == s2[j]) {
            i++;
            j++;
        }
        return {index(s1[i]), index(s2[j])};
    }

    vector<char> bfs(vector<vector<int>> adj) {
        int n = adj.size();
        vector<int> topo(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto it1 : adj[i]) {
                topo[it1] ++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if(topo[i] == 0) {
                q.push(i);
            }
        }
        
        vector<char> ans;
        
        while(!q.empty()) {
            int node = q.front();q.pop();
            ans.emplace_back((char)(node + 'a'));
            for(auto& it : adj[node]) {
                topo[it] --;
                if(topo[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
    
    
public:
    vector<char> mainFunction(int n, int k, vector<string>& dict) {
        vector<vector<int>> adj(k);
        for(int i = 0; i < n-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            pair<int, int> p = getEdge(s1, s2);
            adj[p.first].emplace_back(p.second);
        }

        vector<char> ans = bfs(adj);
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}