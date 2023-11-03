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

    int result = 0;

    pair<int, int> findAvg(TreeNode* root){

        // Leaf Node
        if(root == NULL)
            return make_pair(0, 0);


        pair<int, int> leftChild = findAvg(root->left);
        pair<int, int> rightChild = findAvg(root->right);

        // Find the sum of root
        int c = 1 + leftChild.second + rightChild.second;
        int sum = root->val + leftChild.first + rightChild.first;

        int avg = sum / c;

        if(avg == root->val)
            result++;


        return make_pair(sum, c);
    }

    int averageOfSubtree(TreeNode* root) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        pair<int, int> pr = findAvg(root);
    
        return result;
    }
};