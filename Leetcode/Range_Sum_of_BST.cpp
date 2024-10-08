#include <iostream>
using namespace std;

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

    int totalSum = 0;

    void findSum(TreeNode* root, int low, int high){

        if(root == NULL)
            return;

        if(root->val >= low && root->val <= high)
            totalSum += root->val;

        findSum(root->left, low, high);
        findSum(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        findSum(root, low, high);

        return totalSum;
    }
};