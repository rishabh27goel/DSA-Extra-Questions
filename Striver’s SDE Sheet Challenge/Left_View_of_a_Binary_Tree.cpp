#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class TreeNode {

    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> result;

    if(root == NULL)
        return result;

    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
    
        int size = q.size();
        result.push_back(q.front()->data);

        while (size--) {
        
            TreeNode<int>* node = q.front();
            q.pop();

            if(node->left != NULL){

                q.push(node->left);
            }
        
            if(node->right != NULL){

                q.push(node->right);
            }
        }
    }

    return result;
}