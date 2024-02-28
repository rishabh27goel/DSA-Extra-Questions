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

    int result = 0;

    int findDepth(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftCall = findDepth(root->left);
        int rightCall = findDepth(root->right);

        result = max(leftCall + rightCall, result);
        return max(leftCall, rightCall) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        findDepth(root);
        return result;
    }
};