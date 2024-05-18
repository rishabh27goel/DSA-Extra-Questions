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

    int totalSteps = 0;

    int findMoves(TreeNode* root){

        if(root == NULL)
            return 0;

        int currNeeds = root->val - 1;
        int leftNeeds = findMoves(root->left);
        int rightNeeds = findMoves(root->right);

        totalSteps += (abs(leftNeeds) + abs(rightNeeds));

        // Passed to parents
        return currNeeds + leftNeeds + rightNeeds;
    }

    int distributeCoins(TreeNode* root) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cout.tie(NULL);

        findMoves(root);
        return totalSteps;
    }
};