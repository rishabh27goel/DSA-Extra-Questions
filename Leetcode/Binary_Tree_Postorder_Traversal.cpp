#include <iostream>
#include <vector>
#include <stack>
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
    // vector<int> postorder;
    // void findPostOrder(TreeNode* root) {
    //     if(root == NULL)
    //         return;

    //     findPostOrder(root->left);
    //     findPostOrder(root->right);
    //     postorder.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     findPostOrder(root);
    //     return postorder;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL)  return postorder;
    
        stack<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();

            postorder.push_back(node->val);

            if(node->left != NULL)
                nodes.push(node->left);

            if(node->right != NULL)
                nodes.push(node->right);
        }

        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};