#include <iostream>
#include <vector>
#include <unordered_set>
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
    // vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     if(root == NULL)  return {};

    //     unordered_set<int> toBeDeleted;
    //     for(int i=0; i<to_delete.size(); i++){
    //         toBeDeleted.insert(to_delete[i]);
    //     }

    //     vector<TreeNode*> forest;
    //     queue<TreeNode*> nodes;
    //     nodes.push(root);
    
    //     while(!nodes.empty()){
    //         TreeNode* node = nodes.front();
    //         nodes.pop();

    //         // Check for deleted nodes on left and right
    //         if(node->left != NULL){
    //             nodes.push(node->left);
    //             if(toBeDeleted.find(node->left->val) != toBeDeleted.end())
    //                 node->left = NULL;
    //         }

    //         if(node->right != NULL){
    //             nodes.push(node->right);
    //             if(toBeDeleted.find(node->right->val) != toBeDeleted.end())
    //                 node->right = NULL;
    //         }

    //         // If we have to delete this node
    //         // Its child will be new trees
    //         if(toBeDeleted.find(node->val) != toBeDeleted.end()){
    //             if(node->left != NULL)  forest.push_back(node->left);
    //             if(node->right != NULL)  forest.push_back(node->right);
    //         }
    //     }

    //     // If we are not removing the root only
    //     if(toBeDeleted.find(root->val) == toBeDeleted.end())
    //         forest.push_back(root);

    //     return forest;
    // }

    vector<TreeNode*> forest;
    TreeNode* findForest(TreeNode* root, unordered_set<int> &toBeDeleted){
        // Base Case
        if(root == NULL)
            return NULL;

        root->left = findForest(root->left, toBeDeleted);
        root->right = findForest(root->right, toBeDeleted);
    
        if(toBeDeleted.find(root->val) != toBeDeleted.end()) {
            if(root->left != NULL)  forest.push_back(root->left);
            if(root->right != NULL)  forest.push_back(root->right);
            
            delete root;
            return NULL;
        }

        return root;
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        if(root == NULL)  return {};

        // Push all the nodes to be deleted
        unordered_set<int> toBeDeleted;
        for(int i=0; i<to_delete.size(); i++){
            toBeDeleted.insert(to_delete[i]);
        }

        root = findForest(root, toBeDeleted);
        if(root != NULL)
            forest.push_back(root);

        return forest;
    }
};