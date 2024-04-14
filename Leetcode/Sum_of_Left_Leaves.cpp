#include <iostream>
#include <vector>
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

    int findLeavesSum(TreeNode* root, TreeNode* parent){

        // Base Case
        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL){

            if(parent != NULL && parent->left == root)
                return root->val;

            return 0;
        }

        return findLeavesSum(root->left, root) + findLeavesSum(root->right, root);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        return findLeavesSum(root, NULL);
    }
};