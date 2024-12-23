#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        queue<TreeNode*> nodes;
        nodes.push(root);

        int minOps = 0;
        while(!nodes.empty()) {
            int size = nodes.size();
            
            vector<pair<int, int>> level;
            int counter = 0;

            while(size--) {
                TreeNode* node = nodes.front();
                nodes.pop();

                level.push_back({node->val, counter++});

                if(node->left != NULL)
                    nodes.push(node->left);

                if(node->right != NULL)
                    nodes.push(node->right);
            }

            sort(level.begin(), level.end());

            int moves = 0;
            for(int j = 0; j < level.size(); j++) {
                if(level[j].second == j)    continue;

                while(level[j].second != j) {
                    swap(level[j], level[level[j].second]);
                    moves++;
                } 
            }
            minOps += moves;
        }

        return minOps;
    }
};