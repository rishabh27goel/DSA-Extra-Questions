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
    // Method : Swapping only the values
    // unordered_map<int, vector<TreeNode*>> nodeMap;

    // void addNodes(TreeNode* root, int level) {
    //     if(root == NULL)
    //         return;

    //     nodeMap[level].push_back(root);
    //     addNodes(root->left, level + 1);
    //     addNodes(root->right, level + 1);
    // }

    // TreeNode* reverseOddLevels(TreeNode* root) {
    //     addNodes(root, 0);

    //     for(auto &itr : nodeMap) {
    //         if(itr.first % 2 == 1) {
    //             auto &vt = itr.second;

    //             int i = 0;
    //             int j = vt.size()-1;

    //             while(i <= j) {
    //                 swap(vt[i]->val, vt[j]->val);
    //                 i++;
    //                 j--;
    //             }
    //         }
    //     }

    //     return root;
    // }

    void addNodes(TreeNode* left, TreeNode* right, int level) {
        if(left == NULL || right == NULL)
            return;

        if(level % 2 == 0) {
            swap(left->val, right->val);
        }

        addNodes(left->left, right->right, level + 1);
        addNodes(left->right, right->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL)
            return root;

        if(root->left == NULL || root->right == NULL)
            return root;

        addNodes(root->left, root->right, 0);
        return root;
    }
};