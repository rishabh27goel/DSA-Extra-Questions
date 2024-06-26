#include <iostream>
using namespace std;

// Definition for a binary tree node
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

    void fillTreeNodes(TreeNode* root, vector<TreeNode*> &treeNodes){
        // Base Case
        if(root == NULL)
            return;

        fillTreeNodes(root->left, treeNodes);
        treeNodes.push_back(root);
        fillTreeNodes(root->right, treeNodes);
    }

    TreeNode* createBST(vector<TreeNode*> &tree, int start, int end){
        // Base Case
        if(start > end)
            return NULL;

        int middle = start + (end - start) / 2;

        TreeNode* root = tree[middle];
        TreeNode* leftTree = createBST(tree, start, middle - 1);
        TreeNode* rightTree = createBST(tree, middle + 1, end);

        root->left = leftTree;
        root->right = rightTree;
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<TreeNode*> treeNodes;
        fillTreeNodes(root, treeNodes);

        return createBST(treeNodes, 0, treeNodes.size()-1);
    }
};