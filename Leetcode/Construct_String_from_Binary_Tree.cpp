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
    string tree2str(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        if(root == NULL)
            return "";

        if(root->left == NULL && root->right == NULL)
            return to_string(root->val);

        
        string result = to_string(root->val);
        result += '(';

        if(root->left != NULL){

            result += tree2str(root->left);
        }

        result += ')';

        if(root->right != NULL){

            result += '(';
            result += tree2str(root->right);
            result += ')';
        }

        return result;
    }
};