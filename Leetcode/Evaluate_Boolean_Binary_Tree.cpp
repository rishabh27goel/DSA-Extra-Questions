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

    Solution(){
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);
    }

    bool evaluateTree(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL)
            return root->val;

        bool lC = evaluateTree(root->left);
        bool rC = evaluateTree(root->right);
    
        if(root->val == 2)
            return lC | rC;

        return lC & rC;
    }
};