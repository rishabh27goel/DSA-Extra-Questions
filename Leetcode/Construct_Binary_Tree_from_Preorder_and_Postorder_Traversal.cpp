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
      unordered_map<int, int> postorderIdxMap;
      TreeNode* createTree(vector<int> &preorder, vector<int> &postorder, int start, int end, int &preorderIdx) {
          if(preorderIdx == preorder.size() || start > end)
              return NULL;
  
          TreeNode* currNode = new TreeNode(preorder[preorderIdx++]);
  
          if(preorderIdx == preorder.size() || start == end)
              return currNode;
  
          int divisionIdx = postorderIdxMap[preorder[preorderIdx]];
  
          currNode->left = createTree(preorder, postorder, start, divisionIdx, preorderIdx);
          currNode->right = createTree(preorder, postorder, divisionIdx + 1, end - 1, preorderIdx);
          
          return currNode;
      }
      TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
          int totalNodes = preorder.size();
  
          for(int idx = 0; idx < totalNodes; idx++) 
              postorderIdxMap[postorder[idx]] = idx;
  
          int preorderIdx = 0;
          return createTree(preorder, postorder, 0, totalNodes - 1, preorderIdx);
      }
  };