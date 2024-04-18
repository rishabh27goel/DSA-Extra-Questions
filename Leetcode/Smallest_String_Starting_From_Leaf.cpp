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

    string smallestString = "";

    void findSmallest(TreeNode* root, string &str) {

        // Base Case
        if(root == NULL)
            return;

        str.push_back((char) ('a' + root->val));

        if(root->left == NULL && root->right == NULL){

            string cmp = str;
            reverse(cmp.begin(), cmp.end());

            if (smallestString.empty()) 
                smallestString = cmp;
            else 
                smallestString = min(smallestString, cmp);
        }

        findSmallest(root->left, str);
        findSmallest(root->right, str);

        str.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {

        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        string str = "";
        findSmallest(root, str);

        return smallestString;
    }
};