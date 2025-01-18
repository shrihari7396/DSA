#include <bits/stdc++.h>
using namespace std;

class Node {
public:  // Make data and children public for easier access
    int data;
    Node *left; 
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> bottomView(Node *root) {
        // Check if the tree is empty
        if (root == nullptr) return {};

        map<int, int> m; // To store the bottom view nodes
        queue<pair<Node*, int>> q; // Queue for level order traversal
        q.push({root, 0}); // Start with the root at horizontal distance 0

        while (!q.empty()) {
            auto temp1 = q.front();
            q.pop();
            Node* temp = temp1.first; // Current node
            int x = temp1.second; // Horizontal distance
            
            // Update the map with the current node's value at the horizontal distance
            m[x] = temp->data;

            // If there's a left child, enqueue it with horizontal distance -1
            if (temp->left) {
                q.push({temp->left, x - 1});
            }
            // If there's a right child, enqueue it with horizontal distance +1
            if (temp->right) {
                q.push({temp->right, x + 1});
            }
        }

        // Prepare the result vector in order of horizontal distance
        vector<int> ans;
        for (const auto& ch : m) {
            ans.emplace_back(ch.second); // Use ch.second to get the value
        }
        return ans;
    }
};
