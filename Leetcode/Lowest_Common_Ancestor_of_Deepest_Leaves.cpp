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
      // vector<TreeNode*> deepestLeaves;
      // int maxDepth = 0;
      
      // void getDeepestLeaves(TreeNode* root, int depth) {
      //     if(root == NULL)
      //         return;
  
      //     if(root->left == NULL && root->right == NULL) {
      //         if(maxDepth < depth) {
      //             deepestLeaves.clear();
      //             deepestLeaves.push_back(root);
      //             maxDepth = depth;
      //         }
      //         else if(maxDepth == depth) {
      //             deepestLeaves.push_back(root);
      //         }
      //         return;
      //     }
  
      //     getDeepestLeaves(root->left, depth + 1);
      //     getDeepestLeaves(root->right, depth + 1);
      // }
  
      // TreeNode* getLowestCommonAncestor(TreeNode* root, TreeNode* nodeOne, TreeNode* nodeTwo) {
      //     if(root == NULL)
      //         return NULL;
  
      //     if(root->val == nodeOne->val || root->val == nodeTwo->val)
      //         return root;
  
  
      //     TreeNode* leftChild = getLowestCommonAncestor(root->left, nodeOne, nodeTwo);
      //     TreeNode* rightChild = getLowestCommonAncestor(root->right, nodeOne, nodeTwo);
  
      //     if(leftChild == NULL && rightChild == NULL)
      //         return NULL;
          
      //     else if(leftChild != NULL && rightChild == NULL)
      //         return leftChild;
  
      //     else if(leftChild == NULL && rightChild != NULL)
      //         return rightChild;
  
      //     return root;
      // } 
  
      // TreeNode* lcaDeepestLeaves(TreeNode* root) {
      //     // Get all the deepest leaves nodes
      //     getDeepestLeaves(root, 1);
  
      //     int size = deepestLeaves.size();
  
      //     if(size == 1) 
      //         return deepestLeaves[0];
          
      //     TreeNode* commonNode = getLowestCommonAncestor(root, deepestLeaves[0], deepestLeaves[1]);
      //     if(size == 2)
      //         return commonNode;
  
      //     for(int idx = 2; idx < size; idx++)
      //         commonNode = getLowestCommonAncestor(root, commonNode, deepestLeaves[idx]);
  
      //     return commonNode;
      // }
  
      pair<TreeNode*, int> getLowestCommonAncestor(TreeNode* root) {
          if(root == NULL)
              return make_pair(nullptr, 0);
  
          auto leftChild = getLowestCommonAncestor(root->left);
          auto rightChild = getLowestCommonAncestor(root->right);
      
          if(leftChild.second > rightChild.second)
              return make_pair(leftChild.first, leftChild.second + 1);
  
          else if(leftChild.second < rightChild.second)
              return make_pair(rightChild.first, rightChild.second + 1);
  
          return make_pair(root, rightChild.second + 1);
      }
  
      TreeNode* lcaDeepestLeaves(TreeNode* root) {
          return getLowestCommonAncestor(root).first;
      }
  };