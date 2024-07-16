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
    // Method 1 : Using queue (TLE large inputs)
    // unordered_map<TreeNode*, TreeNode*> parentMap;
    // TreeNode* srcNode = NULL;

    // void findParent(TreeNode* root, TreeNode* parent, int src){
    //     if(root == NULL)
    //         return;

    //     if(root->val == src)  srcNode = root;
    //     parentMap[root] = parent;

    //     findParent(root->left, root, src);
    //     findParent(root->right, root, src);
    // }

    // string getDirections(TreeNode* root, int startValue, int destValue) {
        
    //     // Get the parent map
    //     findParent(root, NULL, startValue);

    //     // Find the shortest distance now
    //     queue<TreeNode*> nodes;
    //     nodes.push(srcNode);

    //     unordered_set<int> visited;
    //     visited.insert(srcNode->val);

    //     // If we taking the direction along with queue it can reach n ^ 2 space in worst case
    //     // So, we will track the direction for a particular node as all the nodes are unique
    //     unordered_map<int, pair<TreeNode*, char>> directionMap;
    //     while(!nodes.empty()){

    //         TreeNode* node = nodes.front();
    //         nodes.pop();

    //         if(node->val == destValue)    
    //             return findDirectionByMap(directionMap, startValue, destValue);  
        
    //         // Push left child
    //         if(node->left != NULL && visited.find(node->left->val) == visited.end()){
    //             nodes.push(node->left);
    //             visited.insert(node->left->val);
    //             directionMap[node->left->val] = make_pair(node, 'L');
    //         }
                
    //         // Push right child
    //         if(node->right != NULL && visited.find(node->right->val) == visited.end()){
    //             nodes.push(node->right);
    //             visited.insert(node->right->val);
    //             directionMap[node->right->val] = make_pair(node, 'R');
    //         }
                
    //         // Push parent node
    //         if(parentMap[node] != NULL && visited.find(parentMap[node]->val) == visited.end()){
    //             nodes.push(parentMap[node]);
    //             visited.insert(parentMap[node]->val);
    //             directionMap[parentMap[node]->val] = make_pair(node, 'U');
    //         }
    //     }

    //     return "";
    // }

    // string findDirectionByMap(unordered_map<int, pair<TreeNode*, char>> &directionMap, int startValue, int destValue){

    //     int start = destValue;
    //     string direction = "";

    //     while(start != startValue){
    //         auto &pr = directionMap[start];
    //         direction.push_back(pr.second);
    //         start = pr.first->val;
    //     }

    //     reverse(direction.begin(), direction.end());
    //     return direction;
    // }

    // Method 2 : Using LCA
    // TreeNode* findLCA(TreeNode* root, int src, int dst){
    //     // Base Case
    //     if(root == NULL)
    //         return NULL;

    //     if(root->val == src || root->val == dst)
    //         return root;

    //     TreeNode* leftChild = findLCA(root->left, src, dst);
    //     TreeNode* rightChild = findLCA(root->right, src, dst);
        
    //     if(leftChild == NULL)
    //         return rightChild;

    //     else if(rightChild == NULL)
    //         return leftChild;

    //     else
    //         return root;;
    // }   

    // string startPath = "";
    // string endPath = "";

    // void findPath(TreeNode* root, string &path, int src, int dst){
    //     if(root == nullptr)
    //         return;

    //     if(root->val == src)  startPath = path;
    //     if(root->val == dst)  endPath = path;

    //     path.push_back('L');
    //     findPath(root->left, path, src, dst);
    //     path.pop_back();

    //     path.push_back('R');
    //     findPath(root->right, path, src, dst);
    //     path.pop_back();
    // }

    // string getDirections(TreeNode* root, int startValue, int destValue) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     // Get the LCA
    //     TreeNode* lcaNode = findLCA(root, startValue, destValue);

    //     cout << lcaNode->val << " ";

    //     // Find the path from LCA
    //     string path = "";
    //     findPath(lcaNode, path, startValue, destValue);

    //     for(int i=0; i<startPath.size(); i++){
    //         startPath[i] = 'U';
    //     }

    //     startPath += endPath;
    //     return startPath;
    // }

    // Method 3: Path from root only 
    string startPath = "";
    string endPath = "";

    void findPath(TreeNode* root, string &path, int src, int dst){
        if(root == nullptr)
            return;

        if(root->val == src)  startPath = path;
        if(root->val == dst)  endPath = path;

        path.push_back('L');
        findPath(root->left, path, src, dst);
        path.pop_back();

        path.push_back('R');
        findPath(root->right, path, src, dst);
        path.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string path = "";
        findPath(root, path, startValue, destValue);

        int i = 0;
        int j = 0;
        while(i < startPath.size() && j < endPath.size()){
            if(startPath[i] != endPath[j])
                break;

            i++, j++;
        }

        string direction = "";
        for(; i<startPath.size(); i++){
            direction.push_back('U');
        }
        for(; j<endPath.size(); j++){
            direction.push_back(endPath[j]);
        }

        return direction;
    }   
};