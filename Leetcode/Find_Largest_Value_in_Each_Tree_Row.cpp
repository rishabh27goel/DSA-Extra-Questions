#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    vector<int> largestValues(TreeNode* root) {
        
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        if(root == NULL)
            return {};

        vector<int> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            int maxVal = INT_MIN;

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                maxVal = max(node->val, maxVal);

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);
            }

            result.push_back(maxVal);
        }

        return result;
    }
};