#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);

        int largestValue = INT_MIN;
        int smallestLevel = -1;

        int startLevel = 1;
        while(!nodes.empty()) {
            int size = nodes.size();
            int currSum = 0;

            while(size--) {
                TreeNode* currNode = nodes.front();
                nodes.pop();

                currSum += currNode->val;

                if(currNode->left != NULL) 
                    nodes.push(currNode->left);
                
                if(currNode->right != NULL) 
                    nodes.push(currNode->right);
            }
            if(largestValue < currSum) {
                smallestLevel = startLevel;
                largestValue = currSum;
            }
            startLevel++;
        }
        return smallestLevel;
    }
};