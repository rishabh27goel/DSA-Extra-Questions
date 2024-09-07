#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool pathExist(ListNode* head, TreeNode* root) {
        // Base Case
        if(head == NULL)
            return true;

        if(root == NULL || head->val != root->val)
            return false;
    
        return pathExist(head->next, root->left) || pathExist(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        // Base Case
        if(root == NULL)
            return false;

        if(root->val == head->val) {
            if(pathExist(head, root))
                return true;
        }

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};