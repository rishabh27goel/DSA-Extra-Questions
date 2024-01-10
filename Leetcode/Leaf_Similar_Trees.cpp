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

    void findLeafs(TreeNode* root, vector<int> &leaf){

        // Base Case
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->val);
            return;
        }

        findLeafs(root->left, leaf);
        findLeafs(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> leaf1;
        vector<int> leaf2;
    
        findLeafs(root1, leaf1);
        findLeafs(root2, leaf2);

        if(leaf1.size() != leaf2.size())
            return false;

        int i = 0;

        while(i < leaf1.size()){

            if(leaf1[i] != leaf2[i])
                return false;
            
            i++;
        }

        return true;
    }
};