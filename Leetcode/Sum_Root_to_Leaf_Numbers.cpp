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

    int result = 0;

    void findSum(TreeNode* root, int total){
    
        // Base Case
        if(root == NULL)
            return;

        total = (total * 10) + root->val;

        if(root->left == NULL && root->right == NULL)
            result += total;

        findSum(root->left, total);
        findSum(root->right, total);
    }

    int sumNumbers(TreeNode* root) {

        findSum(root, 0);

        return result;
    }
};