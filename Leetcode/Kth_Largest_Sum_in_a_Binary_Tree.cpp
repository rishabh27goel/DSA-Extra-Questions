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

#define ll long long

class Solution {
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            int size = nodes.size();

            ll total = 0;
            while(size--) {

                TreeNode* node = nodes.front();
                nodes.pop();

                total += node->val;

                if(node->left != NULL)
                    nodes.push(node->left);

                if(node->right != NULL)
                    nodes.push(node->right);
            }
            
            if(pq.size() < k) {
                pq.push(total);
            }
            else {
                if(total > pq.top()) {
                    pq.pop();
                    pq.push(total);
                }
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};
