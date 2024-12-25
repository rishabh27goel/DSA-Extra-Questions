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
    vector<int> largestValues(TreeNode* root) {
        vector<int> largest;
        if(root == NULL)
            return largest;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            int size = nodes.size();
            int maxNum = INT_MIN;

            while(size--) {
                TreeNode* node = nodes.front();
                nodes.pop();

                maxNum = max(maxNum, node->val);

                if(node->left != NULL)
                    nodes.push(node->left);
                
                if(node->right != NULL)
                    nodes.push(node->right);
            }

            largest.push_back(maxNum);
        }

        return largest;
    }
};