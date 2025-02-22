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
      TreeNode* createTree(string &traversal, int &travIdx, int currDash) {
          int travSize = traversal.size();
          if(travIdx == travSize)
              return NULL;
  
          int rootVal = 0;
          while(travIdx < travSize && traversal[travIdx] >= '0' && traversal[travIdx] <= '9') {
              rootVal = (rootVal * 10) + (traversal[travIdx] - '0');
              travIdx++;
          }
  
          TreeNode* rootNode = new TreeNode(rootVal);
          if(travIdx == travSize)
              return rootNode;
  
          int dashStart = travIdx;
          int dashCount = 0;
  
          while(travIdx < travSize && traversal[travIdx] == '-') {
              dashCount++, travIdx++;
          }
  
          if(dashCount == currDash) {
              rootNode->left = createTree(traversal, travIdx, currDash + 1);
          }
          else {
              travIdx = dashStart;
              return rootNode;
          }
  
          if(travIdx == travSize)
              return rootNode;
  
          dashStart = travIdx;
          dashCount = 0;
  
          while(travIdx < travSize && traversal[travIdx] == '-') {
              dashCount++, travIdx++;
          }
  
          if(dashCount == currDash) {
              rootNode->right = createTree(traversal, travIdx, currDash + 1);
          }
          else {
              travIdx = dashStart;
              return rootNode;
          }
  
          return rootNode;
      }
  
      TreeNode* recoverFromPreorder(string traversal) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int travIdx = 0;
          return createTree(traversal, travIdx, 1);
      }
  };