#include <iostream>
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
    bool isEvenOddTree(TreeNode* root) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool isEven = true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            int prev = isEven ? INT_MIN : INT_MAX;

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                if(node->val % 2 != isEven)
                    return false;

                if(isEven && prev >= node->val)
                    return false;

                if(!isEven && prev <= node->val)
                    return false;


                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);


                prev = node->val;
            }

            isEven = !isEven;
        }

        return true;
    }
};