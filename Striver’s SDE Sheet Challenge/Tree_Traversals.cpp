#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void inorderTrav(BinaryTreeNode<int> *root, vector<int> &inorder) {

    if(root == NULL)
        return;

    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}

void preorderTrav(BinaryTreeNode<int> *root, vector<int> &preorder) {

    if(root == NULL)
        return;

    preorder.push_back(root->data);
    preorderTrav(root->left, preorder);
    preorderTrav(root->right, preorder);
}

void postorderTrav(BinaryTreeNode<int> *root, vector<int> &postorder) {

    if(root == NULL)
        return;

    postorderTrav(root->left, postorder);
    postorderTrav(root->right, postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    
    vector<vector<int>> result;

    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    inorderTrav(root, inorder);
    preorderTrav(root, preorder);
    postorderTrav(root, postorder);

    result.push_back(inorder);
    result.push_back(preorder);
    result.push_back(postorder);

    return result;
}