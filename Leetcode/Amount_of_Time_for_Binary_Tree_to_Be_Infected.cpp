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

    // TreeNode* startNode = NULL;

    // void findParentMap(TreeNode* root, TreeNode* parent, int &start, unordered_map<TreeNode*, TreeNode*> &parentMap){
    //     // Base Case
    //     if(root == NULL)
    //         return;

    //     if(start == root->val)
    //         startNode = root;

    //     parentMap[root] = parent;
    //     findParentMap(root->left, root, start, parentMap);
    //     findParentMap(root->right, root, start, parentMap);
    // }

    // int amountOfTime(TreeNode* root, int start) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     unordered_map<TreeNode*, TreeNode*> parentMap;
    //     findParentMap(root, NULL, start, parentMap);
    
    //     int total = 0;
    //     unordered_set<TreeNode*> infected;

    //     queue<TreeNode*> q;
    //     q.push(startNode);
    //     infected.insert(startNode);
    
    //     while(!q.empty()){

    //         int size = q.size();

    //         while(size--){

    //             TreeNode* node = q.front();
    //             q.pop();

    //             if(parentMap[node] != NULL && infected.find(parentMap[node]) == infected.end()){
    //                 q.push(parentMap[node]);
    //                 infected.insert(parentMap[node]);
    //             }  

    //             if(node->left != NULL && infected.find(node->left) == infected.end()){
    //                 q.push(node->left);
    //                 infected.insert(node->left);
    //             }

    //             if(node->right != NULL && infected.find(node->right) == infected.end()){
    //                 q.push(node->right);
    //                 infected.insert(node->right);
    //             }
    //         }

    //         if(q.empty())
    //             return total;


    //         total++;
    //     }

    //     return total;
    // }

    int maxDistance = 0;

    int findDepthHelper(TreeNode* root, int start){

        if(root == NULL)
            return 0;

        int leftDepth = findDepthHelper(root->left, start);
        int rightDepth = findDepthHelper(root->right, start);

        if(root->val == start){
            maxDistance = max(leftDepth, rightDepth);
            return -1;
        }
        else if(leftDepth >= 0 && rightDepth >= 0){
            return max(leftDepth, rightDepth) + 1;
        }
        else {

            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(distance, maxDistance);
            return min(leftDepth, rightDepth) - 1;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        findDepthHelper(root, start);
        return maxDistance;
    }
};