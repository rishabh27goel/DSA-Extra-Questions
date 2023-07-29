#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    
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

bool checkSymmetric(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2){

    // Base Case
    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) && 
    checkSymmetric(root1->left, root2->right) && 
    checkSymmetric(root1->right, root2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return true;

    return checkSymmetric(root->left, root->right);    
}