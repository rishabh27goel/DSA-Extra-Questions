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
    TreeNode* replaceValueInTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        queue<pair<TreeNode*, int>> nodes;
        nodes.push(make_pair(root, 0));

        queue<TreeNode*> sumQ;
        sumQ.push(root);

        while(!sumQ.empty()) {
            int size = sumQ.size();
            int totalLevel = 0;

            while(size--) {
                TreeNode* node = sumQ.front();
                sumQ.pop();

                if(node->left != NULL) {
                    totalLevel += node->left->val;
                    sumQ.push(node->left);
                }

                if(node->right != NULL) {
                    totalLevel += node->right->val;
                    sumQ.push(node->right);
                }
            }

            size = nodes.size();
            while(size--) {
                auto nodePr = nodes.front();
                nodes.pop();

                TreeNode* node = nodePr.first;
                node->val = nodePr.second;

                int sibling = 0;
                if(node->left != NULL)
                    sibling += node->left->val;

                if(node->right != NULL)
                    sibling += node->right->val;

                if(node->left != NULL)
                    nodes.push(make_pair(node->left, totalLevel - sibling));

                if(node->right != NULL)
                    nodes.push(make_pair(node->right, totalLevel - sibling));
            }
        }

        return root;
    }
};