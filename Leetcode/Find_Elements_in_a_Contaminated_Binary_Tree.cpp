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

class FindElements {
  public:
      vector<bool> exists;
  
      FindElements(TreeNode* root) {
          int size = pow(2, 21);
          exists.resize(size, false);
  
          getVisitedNodes(root, 0);
      }
      
      void getVisitedNodes(TreeNode* root, int rootVal) {
          if(root == NULL)
              return;
  
          exists[rootVal] = true;
          getVisitedNodes(root->left, 2 * rootVal + 1);
          getVisitedNodes(root->right, 2 * rootVal + 2);
      }
  
      bool find(int target) {
          return exists[target];
      }
  };
  
  /**
  Your FindElements object will be instantiated and called as such:
  FindElements* obj = new FindElements(root);
  bool param_1 = obj->find(target);
   */