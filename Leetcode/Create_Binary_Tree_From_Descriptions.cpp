#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = descriptions.size();

        unordered_map<int, TreeNode*> mapping; 
        unordered_set<int> track;

        for(int i=0; i<descriptions.size(); i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int side = descriptions[i][2];
        
            TreeNode* parentNode = (mapping.find(parent) != mapping.end() ? mapping[parent] : new TreeNode(parent));
            TreeNode* childNode = (mapping.find(child) != mapping.end() ? mapping[child] : new TreeNode(child));
            mapping[parent] = parentNode;
            mapping[child] = childNode;

            if(side)  parentNode->left = childNode; 
            else  parentNode->right = childNode; 

            track.insert(child);
        }

        for(auto itr = mapping.begin(); itr != mapping.end(); itr++){
            if(track.find(itr->first) == track.end())
                return itr->second;
        }

        return NULL;
    }
};