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

    int totalPairs = 0;
    vector<int> findGoodPairs(TreeNode* root, int distance){
        // Base Case
        if(root == NULL)  return {};
        if(root->left == NULL && root->right == NULL)  return {1};
    
        vector<int> leftChild = findGoodPairs(root->left, distance);
        vector<int> rightChild = findGoodPairs(root->right, distance);
    
        vector<int> rootVt;
        for(auto l : leftChild){
            if(l + 1 < distance)    
                rootVt.push_back(l + 1);
        }

        for(auto r : rightChild){
            if(r + 1 < distance)    
                rootVt.push_back(r + 1);
        }

        for(auto l : leftChild){
            for(auto r : rightChild){
                if(l + r <= distance)
                    totalPairs++;
            }   
        }

        return rootVt;
    }

    int countPairs(TreeNode* root, int distance) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        findGoodPairs(root, distance);
        return totalPairs;
    }
};