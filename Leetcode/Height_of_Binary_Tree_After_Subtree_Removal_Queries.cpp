#include <iostream>
#include <vector>
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
    int depthArr[100001];
    int heightArr[100001];
    
    int maxNode = 0;
    vector<int> levelMax[100001];

    int fillDepthHeight(TreeNode* root, int height) {
        if(root == NULL)
            return -1;

        int lC = fillDepthHeight(root->left, height + 1);
        int rC = fillDepthHeight(root->right, height + 1);
        int depth = 1 + max(lC, rC);

        maxNode = max(maxNode, root->val);
        heightArr[root->val] = height;
        depthArr[root->val] = depth;

        auto &vt = levelMax[height];
        vt.push_back(root->val);

        sort(vt.begin(), vt.end(), [&](int &node1, int &node2){
            return depthArr[node1] > depthArr[node2];
        });

        if(vt.size() > 2)   vt.pop_back();

        return depth;
    }

    int findQueryDepth(int node) {
        int depth = depthArr[node];
        int height = heightArr[node];

        if(levelMax[height].size() == 1) {
            return height - 1;
        }
        else {
            int first = levelMax[height][0];
            int second = levelMax[height][1];
           
            if(first == node)
                return depthArr[second] + heightArr[second];
            else 
                return depthArr[first] + heightArr[first];
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        fillDepthHeight(root, 0);

        vector<int> result;
        for(int j = 0; j < queries.size(); j++) {
            int depth = findQueryDepth(queries[j]);
            result.push_back(depth);
        }

        return result;
    }
};