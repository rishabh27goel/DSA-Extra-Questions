#include <iostream>
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

    int result = 0;

    void findPathsCount(TreeNode* root, vector<int> &nodeCount){

        if(root == NULL)
            return;

        nodeCount[root->val]++;

        findPathsCount(root->left, nodeCount);
        findPathsCount(root->right, nodeCount);
    
        if(root->left == NULL && root->right == NULL){

            int c = 0;

            for(int i=1; i<10; i++){

                if(nodeCount[i] % 2 != 0)
                    c++;
            }

            if(c <= 1)
                result++;
        }

        nodeCount[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> nodeCount(10, 0);
        findPathsCount(root, nodeCount);

        return result;
    }
};