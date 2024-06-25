#include <iostream>
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

    void updateTree(TreeNode* root, int &totalSum){
        // Base Case
        if(root == NULL)
            return;

        updateTree(root->right, totalSum);
        
        totalSum += root->val;
        root->val = totalSum;
        
        updateTree(root->left, totalSum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        
        int totalSum = 0;
        updateTree(root, totalSum);

        return root;
    }
};