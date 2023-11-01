#include <iostream>
#include <unordered_map>
#include <vector>
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

    int largest = 0;

    void helper(TreeNode* root, unordered_map<int, int> &mp){

        if(root == NULL)
            return;

        helper(root->left, mp);
        largest = max(largest, ++mp[root->val]);
        helper(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> result;

        unordered_map<int, int> mp;
        helper(root, mp);

        for(auto itr = mp.begin(); itr != mp.end(); itr++){

            if(largest == itr->second)
                result.push_back(itr->first);
        }

        return result;
    }
};