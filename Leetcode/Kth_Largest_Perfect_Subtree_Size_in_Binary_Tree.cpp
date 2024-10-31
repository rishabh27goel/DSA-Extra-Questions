#include <iostream>
#include <vector>
#include <queue>
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
    priority_queue<int, vector<int>, greater<int>> pq;
    pair<bool, int> findSubTree(TreeNode* root, int &k) {
        // Base Case
        if(root == NULL)
            return make_pair(true, 0);

        auto leftChild = findSubTree(root->left, k);
        auto rightChild = findSubTree(root->right, k);

        int treeSize = leftChild.second + rightChild.second + 1;
        if(leftChild.first && rightChild.first && leftChild.second == rightChild.second) {
            pq.push(treeSize);
            if(pq.size() > k)
                pq.pop();

            return make_pair(true, treeSize);
        }  

        return make_pair(false, treeSize);
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        findSubTree(root, k);
        return pq.size() < k ? -1 : pq.top();
    }
};