#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // vector<int> post;
    // void findPostOrder(Node* root) {
    //     if(root == NULL)
    //         return;

    //     for(auto child : root->children) {
    //         findPostOrder(child);
    //     }

    //     post.push_back(root->val);
    // }

    // vector<int> postorder(Node* root) {
    //     findPostOrder(root);

    //     return post;
    // }

    vector<int> postorder(Node* root) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        vector<int> post;
        if(root == NULL)    
            return post;


        stack<Node*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            Node* node = nodes.top();
            nodes.pop();

            post.push_back(node->val);

            for(auto child : node->children) {
                nodes.push(child);
            }
        }

        reverse(post.begin(), post.end());
        return post;
    }
};